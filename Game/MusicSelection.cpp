#include "MusicSelection.h"
#include "game_functions.h"
#include <iostream>


MusicSelection::MusicSelection() : currentMusicIndex(0), startGame(false) {
    // 음악 정보 초기화
    musicInfoList = {
        { "music/Aespa-Spicy.wav", sf::Texture(), std::make_shared<sf::Music>() },
        { "music/Aespa-Hold-On-Tight.wav", sf::Texture(), std::make_shared<sf::Music>() },
        { "music/Aespa-Better-Things.wav", sf::Texture(), std::make_shared<sf::Music>() }
    };

    // 텍스처 초기화
    musicTextures = { sf::Texture(), sf::Texture(), sf::Texture() };

    // 이미지 텍스처 미리 로드
    for (size_t i = 0; i < musicTextures.size(); ++i) {
        if (musicTextures[i].loadFromFile("images/music" + std::to_string(i + 1) + ".png")) {
            // 텍스처 로드 성공
        }
    }


    // 버튼 초기화
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
// TODO : next,prev btn 이미지 오류 해결하기
void MusicSelection::run() {
    sf::RenderWindow window(sf::VideoMode(1500, 843), "음악 선택");

    // 음악 로딩 및 재생
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
                    // 중지하고 다음 음악 재생
                    musicInfoList[currentMusicIndex].music->stop();
                    currentMusicIndex = (currentMusicIndex + 1) % musicTextures.size();
                    musicInfoList[currentMusicIndex].music->play();
                }
                else if (prevButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    // 중지하고 이전 음악 재생
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
                // 게임 화면으로 전환
                musicInfoList[currentMusicIndex].music->stop();
                gameStart(currentMusicIndex);
            }
            else {
                // 음악 선택 화면 표시
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
