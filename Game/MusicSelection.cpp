#include "MusicSelection.h"
#include "game_functions.h"
#include <iostream>


MusicSelection::MusicSelection() : currentMusicIndex(0), startGame(false) {
    // ���� ���� �ʱ�ȭ
    musicInfoList = {
        { "music/Aespa-Spicy.wav", sf::Texture(), std::make_shared<sf::Music>() },
        { "music/Aespa-Hold-On-Tight.wav", sf::Texture(), std::make_shared<sf::Music>() },
        { "music/Aespa-Better-Things.wav", sf::Texture(), std::make_shared<sf::Music>() }
    };

    // �ؽ�ó �ʱ�ȭ
    musicTextures = { sf::Texture(), sf::Texture(), sf::Texture() };

    // �̹��� �ؽ�ó �̸� �ε�
    for (size_t i = 0; i < musicTextures.size(); ++i) {
        if (musicTextures[i].loadFromFile("images/music" + std::to_string(i + 1) + ".png")) {
            // �ؽ�ó �ε� ����
        }
    }


    // ��ư �ʱ�ȭ
    nextButton.setSize(sf::Vector2f(134, 134));
    nextButton.setPosition(1366, 401);
    sf::Texture nextButtonTexture;
    if (nextButtonTexture.loadFromFile("images/next_btn.png")) {
        nextButton.setTexture(&nextButtonTexture);
    }
    else {
        std::cout << "error";
    }

    prevButton.setSize(sf::Vector2f(134, 134));
    prevButton.setPosition(0, 401);
    sf::Texture prevButtonTexture;
    if (prevButtonTexture.loadFromFile("images/prev_btn.png")) {
        prevButton.setTexture(&prevButtonTexture);
    }
}
// TODO : next,prev btn �̹��� ���� �ذ��ϱ�
void MusicSelection::run() {
    sf::RenderWindow window(sf::VideoMode(1500, 843), "���� ����");

    // ���� �ε� �� ���
    for (size_t i = 0; i < musicInfoList.size(); ++i) {
        if (musicInfoList[i].music->openFromFile(musicInfoList[i].path)) {
            musicInfoList[i].music->stop();
        }
    }

    musicInfoList[currentMusicIndex].music->play();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (!startGame && event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (nextButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    // �����ϰ� ���� ���� ���
                    musicInfoList[currentMusicIndex].music->stop();
                    currentMusicIndex = (currentMusicIndex + 1) % musicTextures.size();
                    musicInfoList[currentMusicIndex].music->play();
                }
                else if (prevButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    // �����ϰ� ���� ���� ���
                    musicInfoList[currentMusicIndex].music->stop();
                    currentMusicIndex = (currentMusicIndex - 1 + musicTextures.size()) % musicTextures.size();
                    musicInfoList[currentMusicIndex].music->play();
                }
                else {
                    startGame = true;
                }
            }

            window.clear();

            if (startGame) {
                // ���� ȭ������ ��ȯ
                musicInfoList[currentMusicIndex].music->stop();
                gameStart(currentMusicIndex);
            }
            else {
                // ���� ���� ȭ�� ǥ��
                sf::Sprite musicSprite(musicTextures[currentMusicIndex]);
                musicSprite.setPosition(0, 0);
                window.draw(musicSprite);
                window.draw(nextButton);
                window.draw(prevButton);
                
            }

            window.display();
        }
    }
}
