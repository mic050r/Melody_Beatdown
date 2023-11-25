#include "MusicSelection.h"
#include "game_functions.h"
#include "constants.h"

#include <iostream>
#include <string>
// MusicSelection Ŭ����: ���� ���� ȭ��� ���õ� ����� ����ϴ� Ŭ����
MusicSelection::MusicSelection() : currentMusicIndex(0), startGame(false) {
    // ���� ���� �ʱ�ȭ

    musicInfoList = {
        { "music/Aespa-Spicy.wav", sf::Texture(), std::make_shared<sf::Music>() },
        { "music/Aespa-Hold-On-Tight.wav", sf::Texture(), std::make_shared<sf::Music>() },
        { "music/Aespa-Better-Things.wav", sf::Texture(), std::make_shared<sf::Music>() }
    };

    // musicTextures: ���� ���� ȭ�鿡 ���� �̹��� �ؽ�ó�� �����ϴ� ����
    musicTextures = { sf::Texture(), sf::Texture(), sf::Texture() };

    // �̹��� �ؽ�ó �̸� �ε�
    for (size_t i = 0; i < musicTextures.size(); ++i) {
        if (musicTextures[i].loadFromFile("images/music" + std::to_string(i + 1) + ".png")) {
            // �ؽ�ó �ε� ����
        }
    }   
}

// MusicSelection Ŭ������ run �Լ�: ���� ���� ȭ�� ����
void MusicSelection::run() {
    sf::RenderWindow window(sf::VideoMode(kWindowWidth, kWindowHeight), "Choose Music!");
    
    DisplayButton(window, nextButton, nextButtonPath, nextButtonTexture, 1366, 401, 134, 134);
    DisplayButton(window, prevButton, prevButtonPath, prevButtonTexture, 0, 401, 134, 134);

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
                window.draw(prevButton);
                window.draw(nextButton);
            }
            window.display();
        }
    }
}
