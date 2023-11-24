// ResultScreen.cpp

#include "ResultScreen.h"
#include "game_functions.h"
#include <iostream>

ResultScreen::ResultScreen(int combo, int PERFECT, int GOOD, int MISS, int nowSelected) : window(sf::VideoMode(800, 600), "Result Screen") {
    window.setFramerateLimit(60);

    this->nowSelected = nowSelected;
    std::cout << nowSelected;
    // ���� ���� ȭ���� ��� �̹��� �ε�
    if (!backgroundTexture.loadFromFile("images/result_background.png")) {
        std::cerr << "�̹��� �ε� ����" << std::endl;
        // �̹��� �ε� ���� �� ���� ó�� �Ǵ� ������� ������ �� �ֽ��ϴ�.
        return;
    }


    if (!font.loadFromFile("font/NanumGothic-Bold.ttf")) {
        std::cerr << "��Ʈ �ҷ����� ����" << std::endl;
        // ���� ó�� ���� �߰��� �� �ֽ��ϴ�.
    }

    comboText.setFont(font);
    comboText.setCharacterSize(40);
    comboText.setPosition(390, 466);

    comboText.setString(std::to_string(combo));

    FText.setFont(font);
    FText.setCharacterSize(40);
    FText.setPosition(480, 181);

    FText.setString(std::to_string(PERFECT));

    GText.setFont(font);
    GText.setCharacterSize(40);
    GText.setPosition(480, 258);

    GText.setString(std::to_string(GOOD));

    MText.setFont(font);
    MText.setCharacterSize(40);
    MText.setPosition(480, 330);

    MText.setString(std::to_string(MISS));
}

void ResultScreen::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                // ���콺 ��ư�� ������ ���� ó��
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // ��ư�� Ŭ�� ���� Ȯ��
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (retry.getGlobalBounds().contains(mousePos)) {
                        // ��ư�� Ŭ������ ���� ����
                        std::cout << "retry Ŭ����" << std::endl << nowSelected;
                        gameStart(nowSelected);
                    } else if (select.getGlobalBounds().contains(mousePos)) {
                        // ��ư�� Ŭ������ ���� ����
                        std::cout << "select Ŭ����" << std::endl;
                        HandleMouseClick(select, mousePos);
                    }
                }
            }
        }

        window.clear();
        DisplayBackground(window, backgroundTexture);  // ��� �̹����� â�� ������
        DisplayButton(window, retry, "images/retry.png", retryTexture, 569, 527, 231, 63);
        DisplayButton(window, select, "images/select_music.png", selectTexture, 33, 528, 184, 63); 

        // �޺� �ؽ�Ʈ �׸���
        window.draw(comboText);
        window.draw(FText);
        window.draw(GText);
        window.draw(MText);

        window.display();
    }
}