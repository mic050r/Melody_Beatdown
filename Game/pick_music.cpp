#include <vector>
#include "game_functions.h"
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

// MusicInfo 구조체를 정의하여 음악 관련 정보를 쉽게 관리
struct MusicInfo {
    string path;
    Texture texture;
    shared_ptr<Music> music;
};

void pick_music() {
    RenderWindow window(VideoMode(1500, 843), "음악 선택");

    // 음악 정보를 저장하는 벡터
    vector<MusicInfo> musicInfoList = {
        {"music/Aespa-Spicy.wav", Texture(), make_shared<Music>()},
        {"music/Aespa-Hold-On-Tight.wav", Texture(), make_shared<Music>()},
        {"music/Aespa-Better-Things.wav", Texture(), make_shared<Music>()}
    };

    // 이미지 텍스처를 저장하는 벡터
    vector<Texture> musicTextures = {
        Texture(), Texture(), Texture()
    };

    // 이미지 텍스처를 미리 로드
    for (size_t i = 0; i < musicTextures.size(); ++i) {
        if (musicTextures[i].loadFromFile("images/music" + to_string(i + 1) + ".png")) {
            // 텍스처 로드 성공
        }
    }

    int currentMusicIndex = 0;

    RectangleShape nextButton(Vector2f(134, 134));
    nextButton.setPosition(1366, 401);
    Texture nextButtonTexture;
    if (nextButtonTexture.loadFromFile("images/next_btn.png")) {
        nextButton.setTexture(&nextButtonTexture);
    }

    RectangleShape prevButton(Vector2f(134, 134));
    prevButton.setPosition(0, 401);
    Texture prevButtonTexture;
    if (prevButtonTexture.loadFromFile("images/prev_btn.png")) {
        prevButton.setTexture(&prevButtonTexture);
    }

    bool startGame = false;

    // 음악 로딩 및 재생
    for (size_t i = 0; i < musicInfoList.size(); ++i) {
        if (musicInfoList[i].music->openFromFile(musicInfoList[i].path)) {
            musicInfoList[i].music->stop();
        }
    }

    musicInfoList[currentMusicIndex].music->play();

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (!startGame && event.type == Event::MouseButtonPressed) {
                Vector2i mousePos = Mouse::getPosition(window);
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
                // TODO: 게임 화면을 구현하기
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

}

