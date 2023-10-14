#include "game_functions.h"

using namespace sf;

void start() {
    RenderWindow window(VideoMode(1500, 843), "리듬 게임");

    Texture texture;
    if (!texture.loadFromFile("images/start_background.png")) {
        return;
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            else if (event.type == Event::MouseButtonPressed) {
                // 화면 클릭 이벤트 감지
                pick_music(); // "pick_music" 함수 호출로 화면 전환
                window.close();
            }
        }

        window.clear();

        DisplayBackground(window, texture);

        window.display();
    }
}
