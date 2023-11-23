// ResultScreen.cpp

#include "ResultScreen.h"
#include "game_functions.h"
#include <iostream>

ResultScreen::ResultScreen(int combo, int PERFECT, int GOOD, int MISS) : window(sf::VideoMode(800, 600), "Result Screen") {
    window.setFramerateLimit(60);

    // 게임 시작 화면의 배경 이미지 로드
    if (!backgroundTexture.loadFromFile("images/result_background.png")) {
        std::cerr << "이미지 로드 실패" << std::endl;
        // 이미지 로드 실패 시 예외 처리 또는 디버깅을 수행할 수 있습니다.
        return;
    }


    if (!font.loadFromFile("font/NanumGothic-Bold.ttf")) {
        std::cerr << "폰트 불러오기 실패" << std::endl;
        // 예외 처리 등을 추가할 수 있습니다.
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
                // 마우스 버튼이 눌렸을 때의 처리
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // 버튼의 클릭 여부 확인
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (retry.getGlobalBounds().contains(mousePos)) {
                        // 버튼을 클릭했을 때의 동작
                        std::cout << "클릭됨" << std::endl;
                        HandleMouseClick(retry, mousePos);
                    }
                }
            }
        }

        window.clear();
        DisplayBackground(window, backgroundTexture);  // 배경 이미지를 창에 렌더링
        DisplayButton(window, retry, "images/select_music.png", retryTexture, 285, 562, 197, 22);

        // 콤보 텍스트 그리기
        window.draw(comboText);
        window.draw(FText);
        window.draw(GText);
        window.draw(MText);

        window.display();
    }
}
