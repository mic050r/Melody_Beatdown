#include "game_functions.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

bool isButtonClicked(const RectangleShape& button, const Vector2f& clickPosition) {
    return button.getGlobalBounds().contains(clickPosition);
}

void gameStart(int nowSelected) {
    RenderWindow window(VideoMode(1500, 843), "게임 화면");

    // 선택한 음악에 따라 배경 이미지 및 노트 이미지 파일 이름 구성
    string backgroundFilename = "images/g_background" + to_string(nowSelected + 1) + ".png";
    //string noteFilename = "g_note" + to_string(nowSelected) + ".png";

    Texture backgroundTexture;
    if (backgroundTexture.loadFromFile(backgroundFilename)) {
        // 배경 이미지 로드 성공
    }

    //Texture noteTexture;
    //if (noteTexture.loadFromFile(noteFilename)) {
    //    // 노트 이미지 로드 성공
    //}

    RectangleShape prevButton(Vector2f(80, 80));
    prevButton.setPosition(25, 23);
    Texture prevButtonTexture;
    if (prevButtonTexture.loadFromFile("images/music_prev_btn.png")) {
        prevButton.setTexture(&prevButtonTexture);
    }

    // 게임 루프
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePosition = Mouse::getPosition(window);
                    Vector2f mousePositionF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

                    //TODO : 이전으로 돌아갈 때 선택한 음악으로 돌아가게 만들기
                    // prevButton이 클릭되었을 때 pick_music() 함수 실행
                    if (isButtonClicked(prevButton, mousePositionF)) {
                        pick_music();
                    }
                }
            }
        }

        window.clear();

        // 게임 화면 표시
        DisplayBackground(window, backgroundTexture);
        //DisplayNote(window, noteTexture, x, y);
        window.draw(prevButton);
        
        window.display();
    }
}
