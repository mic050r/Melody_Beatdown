#include "game_functions.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;


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

    // 게임 루프
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        // 게임 화면 표시
        DisplayBackground(window, backgroundTexture);
        //DisplayNote(window, noteTexture, x, y);

        window.display();
    }
}
