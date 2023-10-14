#include <SFML/Graphics.hpp>
#include "game_functions.h"  // game_functions.h 헤더 파일을 포함

using namespace sf;  // SFML 네임스페이스를 사용

int main()
{
    RenderWindow window(VideoMode(1500, 843), "리듬 게임");

    Texture texture;
    if (!texture.loadFromFile("images/start_background.png")) {
        return 1;
    }

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        DisplayBackground(window, texture);  // DisplayBackground 함수 호출

        window.display();
    }

    return 0;
}
