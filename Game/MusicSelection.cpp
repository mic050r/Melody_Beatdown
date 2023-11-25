#include "MusicSelection.h"
#include "game_functions.h"
#include "constants.h"

#include <iostream>
#include <string>
// MusicSelection 클래스: 음악 선택 화면과 관련된 기능을 담당하는 클래스
MusicSelection::MusicSelection() : currentMusicIndex(0), startGame(false) {
    // 음악 정보 초기화

    musicInfoList = {
        { "music/Aespa-Spicy.wav", sf::Texture(), std::make_shared<sf::Music>() },
        { "music/Aespa-Hold-On-Tight.wav", sf::Texture(), std::make_shared<sf::Music>() },
        { "music/Aespa-Better-Things.wav", sf::Texture(), std::make_shared<sf::Music>() }
    };

    // musicTextures: 음악 선택 화면에 사용될 이미지 텍스처를 저장하는 벡터
    musicTextures = { sf::Texture(), sf::Texture(), sf::Texture() };

    // 이미지 텍스처 미리 로드
    for (size_t i = 0; i < musicTextures.size(); ++i) {
        if (musicTextures[i].loadFromFile("images/music" + std::to_string(i + 1) + ".png")) {
            // 텍스처 로드 성공
        }
    }   
}

// MusicSelection 클래스의 run 함수: 음악 선택 화면 실행
void MusicSelection::run() {
    sf::RenderWindow window(sf::VideoMode(kWindowWidth, kWindowHeight), "Choose Music!");
    
    DisplayButton(window, nextButton, nextButtonPath, nextButtonTexture, 1366, 401, 134, 134);
    DisplayButton(window, prevButton, prevButtonPath, prevButtonTexture, 0, 401, 134, 134);

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
                window.draw(prevButton);
                window.draw(nextButton);
            }
            window.display();
        }
    }
}
