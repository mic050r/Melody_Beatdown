#include <vector>
#include "game_functions.h"

using namespace sf;
using namespace std;

void pick_music() {
    RenderWindow window(VideoMode(1500, 843), "음악 선택");

    // 이미지 텍스처를 저장하는 벡터
    vector<Texture> musicTextures;

    Texture music1Texture;
    if (music1Texture.loadFromFile("images/music_spicy.png")) {
        musicTextures.push_back(music1Texture);
    }

    Texture music2Texture;
    if (music2Texture.loadFromFile("images/music_spicy2.png")) {
        musicTextures.push_back(music2Texture);
    }

    Texture music3Texture;
    if (music3Texture.loadFromFile("images/music_spicy3.png")) {
        musicTextures.push_back(music3Texture);
    }

    int currentMusicIndex = 0;

    RectangleShape nextButton(Vector2f(29, 57));
    Texture nextButtonTexture;
    if (nextButtonTexture.loadFromFile("images/next_btn.png")) {
        nextButton.setTexture(&nextButtonTexture);
        nextButton.setPosition(1415, 396);
        nextButton.setFillColor(Color::White);
    }

    RectangleShape prevButton(Vector2f(29, 57));
    Texture prevButtonTexture;
    if (prevButtonTexture.loadFromFile("images/prev_btn.png")) {
        prevButton.setTexture(&prevButtonTexture);
        prevButton.setPosition(56, 396);
        prevButton.setFillColor(Color::White);
    }

    bool startGame = false;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            // TODO : next, prev 버튼 누르면 다른 이미지 나오게 만들기
            if (!startGame && event.type == Event::MouseButtonPressed) {
                Vector2i mousePos = Mouse::getPosition(window);
                if (nextButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    // 다음 음악 텍스처로 업데이트
                    currentMusicIndex = (currentMusicIndex + 1) % musicTextures.size();
                }
                else if (prevButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    // 이전 음악 텍스처로 업데이트
                    currentMusicIndex = (currentMusicIndex - 1 + musicTextures.size()) % musicTextures.size();
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
