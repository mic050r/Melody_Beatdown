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
    string gameInfoFilename = "images/gameInfo.png";
    string judgementLineFilename = "images/judgementLine.png";
    string noteBasicFilename = "images/noteBasic.png";
    string noteRouteFilename = "images/noteRoute.png";
    string noteRouteLineFilename = "images/noteRouteLine.png";
    //string noteRouteLineFilename = "images/noteRouteLine.png";

    Font font;

    if (!font.loadFromFile("font/NanumGothic-Bold.ttf")) {
        // 폰트 파일 경로를 설정
    }

    Texture backgroundTexture;
    if (backgroundTexture.loadFromFile(backgroundFilename)) {
        // 배경 이미지 로드 성공
    }
    
    Texture gameInfoTexture;
    if (gameInfoTexture.loadFromFile(gameInfoFilename)) {
        // 게임 이미지 로드 성공
    }

    Texture judgementLineTexture;
    if (judgementLineTexture.loadFromFile(judgementLineFilename)) {
        // 게임 이미지 로드 성공
    }

    Texture noteRouteTexture;
    if (noteRouteTexture.loadFromFile(noteRouteFilename)) {
        // 게임 이미지 로드 성공
    }

    Texture noteRouteLineTexture;
    if (noteRouteLineTexture.loadFromFile(noteRouteLineFilename)) {
        // 게임 이미지 로드 성공
    }

    Texture noteBasicTexture;
    if (noteBasicTexture.loadFromFile(noteBasicFilename)) {
        // 게임 이미지 로드 성공
    }

    
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
        DisplayNote(window, noteRouteLineTexture, 190, 0);
        DisplayNote(window, noteRouteLineTexture, 331, 0);
        DisplayNote(window, noteRouteLineTexture, 471, 0);
        DisplayNote(window, noteRouteLineTexture, 611, 0);
        DisplayNote(window, noteRouteLineTexture, 884, 0);
        DisplayNote(window, noteRouteLineTexture, 1025, 0);
        DisplayNote(window, noteRouteLineTexture, 1025, 0);
        DisplayNote(window, noteRouteLineTexture, 1165, 0);
        DisplayNote(window, noteRouteLineTexture, 1310, 0);

        DisplayNote(window, gameInfoTexture, 0, 763);
        DisplayNote(window, noteRouteTexture, 190, 0);
        DisplayNote(window, noteRouteTexture, 330, 0);
        DisplayNote(window, noteRouteTexture, 470, 0);
        DisplayNote(window, noteRouteTexture, 610, 0);
        DisplayNote(window, noteRouteTexture, 750, 0);
        DisplayNote(window, noteRouteTexture, 890, 0);
        DisplayNote(window, noteRouteTexture, 1030, 0);
        DisplayNote(window, noteRouteTexture, 1170, 0);

        DisplayNote(window, noteBasicTexture, 194, 358);
        DisplayNote(window, noteBasicTexture, 335, 240);
        DisplayNote(window, noteBasicTexture, 474, 512);
        DisplayNote(window, noteBasicTexture, 681, 422);
        DisplayNote(window, noteBasicTexture, 888, 23);
        DisplayNote(window, noteBasicTexture, 1029, 240);
        DisplayNote(window, noteBasicTexture, 1172, 382);


        
        
        DisplayNote(window, judgementLineTexture, 0, 660);
         
        DisplayText(window, "S", font, 50, Color::White, 250, 656);
        DisplayText(window, "D", font, 50, Color::White, 384, 656);
        DisplayText(window, "F", font, 50, Color::White, 534, 656);
        DisplayText(window, "SPACE BAR", font, 40, Color::White, 630, 656);
        DisplayText(window, "J", font, 50, Color::White, 938, 656);
        DisplayText(window, "K", font, 50, Color::White, 1083, 656);
        DisplayText(window, "L", font, 50, Color::White, 1227, 656);
        
        
        DisplayText(window, "Spicy", font, 50, Color::White, 15, 771);
        DisplayText(window, "000000", font, 50, Color::White, 657, 774);


        //DisplayNote(window, noteTexture, x, y);

        window.draw(prevButton);
        
        window.display();
    }
}
