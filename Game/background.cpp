#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace sf;

// ��� �̹����� ȭ�鿡 ǥ���ϴ� �Լ�
void DisplayBackground(RenderWindow& window, Texture& backgroundTexture) {
    // ��� �̹����� Sprite�� ����
    Sprite background;
    background.setTexture(backgroundTexture);

    // ȭ�鿡 ��� �̹����� �׸�
    window.draw(background);
}

// ��Ʈ �̹����� ȭ�鿡 ǥ���ϴ� �Լ�
void DisplayNote(RenderWindow& window, Texture& noteTexture, int x, int y) {
    // ��Ʈ �̹����� Sprite�� ����
    Sprite note;
    note.setTexture(noteTexture);

    // ��Ʈ�� ��ġ�� ����
    note.setPosition(x, y);

    // ȭ�鿡 ��Ʈ �̹����� �׸�
    window.draw(note);
}

int backgroud() {
    RenderWindow window(VideoMode(800, 600), "Rhythm Game");

    // ���� ���� �õ� �ʱ�ȭ
    srand(static_cast<unsigned>(time(nullptr)));

    // ��� �̹��� �ε�
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background.png")) {
        std::cerr << "��� �̹����� ã�� �� �����ϴ�!" << std::endl;
        return 1;
    }

    // ��Ʈ �̹��� �ε�
    Texture noteTexture;
    if (!noteTexture.loadFromFile("note.png")) {
        std::cerr << "��Ʈ �̹����� ã�� �� �����ϴ�!" << std::endl;
        return 1;
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        // ��Ʈ �ð��� ��ġ�� �ùķ��̼� (������)
        int noteX = rand() % 800; // 0���� 799 ������ ������ x ��ǥ
        int noteY = rand() % 600; // 0���� 599 ������ ������ y ��ǥ

        window.clear();
        DisplayBackground(window, backgroundTexture);
        DisplayNote(window, noteTexture, noteX, noteY);
        window.display();
    }

    return 0;
}
