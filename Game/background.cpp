#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace sf;

// 배경 이미지를 화면에 표시하는 함수
void DisplayBackground(RenderWindow& window, Texture& backgroundTexture) {
    // 배경 이미지를 Sprite로 설정
    Sprite background;
    background.setTexture(backgroundTexture);

    // 화면에 배경 이미지를 그림
    window.draw(background);
}

// 노트 이미지를 화면에 표시하는 함수
void DisplayNote(RenderWindow& window, Texture& noteTexture, int x, int y) {
    // 노트 이미지를 Sprite로 설정
    Sprite note;
    note.setTexture(noteTexture);

    // 노트의 위치를 설정
    note.setPosition(x, y);

    // 화면에 노트 이미지를 그림
    window.draw(note);
}

int backgroud() {
    RenderWindow window(VideoMode(800, 600), "Rhythm Game");

    // 난수 생성 시드 초기화
    srand(static_cast<unsigned>(time(nullptr)));

    // 배경 이미지 로드
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background.png")) {
        std::cerr << "배경 이미지를 찾을 수 없습니다!" << std::endl;
        return 1;
    }

    // 노트 이미지 로드
    Texture noteTexture;
    if (!noteTexture.loadFromFile("note.png")) {
        std::cerr << "노트 이미지를 찾을 수 없습니다!" << std::endl;
        return 1;
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        // 노트 시간과 위치를 시뮬레이션 (예제용)
        int noteX = rand() % 800; // 0부터 799 사이의 임의의 x 좌표
        int noteY = rand() % 600; // 0부터 599 사이의 임의의 y 좌표

        window.clear();
        DisplayBackground(window, backgroundTexture);
        DisplayNote(window, noteTexture, noteX, noteY);
        window.display();
    }

    return 0;
}
