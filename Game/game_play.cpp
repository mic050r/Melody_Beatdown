#include "game_functions.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;


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

    // ���� ����
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        // ���� ȭ�� ǥ��
        DisplayBackground(window, backgroundTexture);
        //DisplayNote(window, noteTexture, x, y);

        window.display();
    }
}
