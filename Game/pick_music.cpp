#include <vector>
#include "game_functions.h"
#include <SFML/Audio.hpp>
//#include <memory>

using namespace sf;
using namespace std;

void pick_music() {
    RenderWindow window(VideoMode(1500, 843), "음악 선택");


    // 음악 파일 경로를 저장할 벡터
    vector<string> musicPaths = {
        "music/Aespa-Spicy.wav",
        "music/Aespa-Hold-On-Tight.wav",
        "music/Aespa-Better-Things.wav"
    };

    // 스마트 포인터를 사용하여 음악 객체 관리
    vector<shared_ptr<Music>> musicVector;

    for (const std::string& path : musicPaths) {
        std::shared_ptr<sf::Music> music = std::make_shared<sf::Music>();
        if (music->openFromFile(path)) {
            musicVector.push_back(music);
        }
    }


    // 이미지 텍스처를 저장하는 벡터
    vector<Texture> musicTextures;

    Texture music1Texture;
    if (music1Texture.loadFromFile("images/music_spicy.png")) {
        musicTextures.push_back(music1Texture);
    }

    Texture music2Texture;
    if (music2Texture.loadFromFile("images/music_hot.png")) {
        musicTextures.push_back(music2Texture);
    }

    Texture music3Texture;
    if (music3Texture.loadFromFile("images/music_bt.png")) {
        musicTextures.push_back(music3Texture);
    }

    int currentMusicIndex = 0;

    RectangleShape nextButton(Vector2f(134, 134));
    Texture nextButtonTexture;
    if (nextButtonTexture.loadFromFile("images/next_btn.png")) {
        nextButton.setTexture(&nextButtonTexture);
        nextButton.setPosition(1366, 401);
    }

    RectangleShape prevButton(Vector2f(134, 134));
    Texture prevButtonTexture;
    if (prevButtonTexture.loadFromFile("images/prev_btn.png")) {
        prevButton.setTexture(&prevButtonTexture);
        prevButton.setPosition(0, 401);
    }

    bool startGame = false;

    // TODO : 처음 곡 선택화면에서 음악 재생 안되는 오류 해결하기 + 음악 소리 겹치는거 해결하기
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (!startGame && event.type == Event::MouseButtonPressed) {
                Vector2i mousePos = Mouse::getPosition(window);   
                if (nextButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    // 다음 음악 텍스처로 업데이트
                    currentMusicIndex = (currentMusicIndex + 1) % musicTextures.size();
                    // 현재 재생 중인 음악 멈추고 다음 음악 재생
                    if (currentMusicIndex < musicVector.size()) {
                        musicVector[currentMusicIndex]->stop();
                        musicVector[currentMusicIndex]->play();
                    }
                }
                else if (prevButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    // 이전 음악 텍스처로 업데이트
                    currentMusicIndex = (currentMusicIndex - 1 + musicTextures.size()) % musicTextures.size();
                    if (currentMusicIndex >= 0 && currentMusicIndex < musicVector.size()) {
                        musicVector[currentMusicIndex]->stop();
                        musicVector[currentMusicIndex]->play();
                    }
                }
                else {
                    startGame = true;
                }
            }
        }

        window.clear();

        if (startGame) {
            // TODO : 게임 화면으로 전환
            // 여기에서 DisplayBackground 및 DisplayNote 함수를 사용하여 리듬 게임 화면을 구현
            // 예: DisplayBackground(window, backgroundTexture);
            // 예: DisplayNote(window, noteTexture, x, y);
        }
        else {
            // 음악 선택 화면 표시
            Sprite musicSprite(musicTextures[currentMusicIndex]);
            musicSprite.setPosition(0, 0);
            window.draw(musicSprite);
            window.draw(nextButton);
            window.draw(prevButton);
        }

        window.display();
    }
}
