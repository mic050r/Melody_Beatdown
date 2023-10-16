#include "game_functions.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

bool isButtonClicked(const RectangleShape& button, const Vector2f& clickPosition) {
    return button.getGlobalBounds().contains(clickPosition);
}

void gameStart(int nowSelected) {
    RenderWindow window(VideoMode(1500, 843), "���� ȭ��");

    // ������ ���ǿ� ���� ��� �̹��� �� ��Ʈ �̹��� ���� �̸� ����
    string backgroundFilename = "images/g_background" + to_string(nowSelected + 1) + ".png";
    //string noteFilename = "g_note" + to_string(nowSelected) + ".png";

    Texture backgroundTexture;
    if (backgroundTexture.loadFromFile(backgroundFilename)) {
        // ��� �̹��� �ε� ����
    }

    //Texture noteTexture;
    //if (noteTexture.loadFromFile(noteFilename)) {
    //    // ��Ʈ �̹��� �ε� ����
    //}

    RectangleShape prevButton(Vector2f(80, 80));
    prevButton.setPosition(25, 23);
    Texture prevButtonTexture;
    if (prevButtonTexture.loadFromFile("images/music_prev_btn.png")) {
        prevButton.setTexture(&prevButtonTexture);
    }

    // ���� ����
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

                    //TODO : �������� ���ư� �� ������ �������� ���ư��� �����
                    // prevButton�� Ŭ���Ǿ��� �� pick_music() �Լ� ����
                    if (isButtonClicked(prevButton, mousePositionF)) {
                        pick_music();
                    }
                }
            }
        }

        window.clear();

        // ���� ȭ�� ǥ��
        DisplayBackground(window, backgroundTexture);
        //DisplayNote(window, noteTexture, x, y);
        window.draw(prevButton);
        
        window.display();
    }
}
