#include <SFML/Graphics.hpp>
#include "game_functions.h"  // game_functions.h ��� ������ ����

using namespace sf;  // SFML ���ӽ����̽��� ���

int main()
{
    RenderWindow window(VideoMode(1500, 843), "���� ����");

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

        DisplayBackground(window, texture);  // DisplayBackground �Լ� ȣ��

        window.display();
    }

    return 0;
}
