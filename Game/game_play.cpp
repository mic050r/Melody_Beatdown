#include "game_functions.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

const string kFontPath = "font/NanumGothic-Bold.ttf";
const string kBackgroundPath = "images/g_background";
const string kGameInfoPath = "images/gameInfo.png";
const string kJudgementLinePath = "images/judgementLine.png";
const string kNoteRoutePath = "images/noteRoute.png";
const string kNoteRouteLinePath = "images/noteRouteLine.png";
const string kNoteBasicPath = "images/noteBasic.png";

bool isButtonClicked(const RectangleShape& button, const Vector2f& clickPosition) {
    return button.getGlobalBounds().contains(clickPosition);
}

void HandleMouseClick(const RectangleShape& button, const Vector2f& clickPosition) {
    if (isButtonClicked(button, clickPosition)) {
        pick_music();
    }
}


void gameStart(int nowSelected) {
    RenderWindow window(VideoMode(1500, 843), "���� ȭ��");
    Font font;

    if (!font.loadFromFile(kFontPath)) {
        // ��Ʈ ���� ��θ� ����
    }

    Texture backgroundTexture, gameInfoTexture, judgementLineTexture, noteRouteTexture, noteRouteLineTexture, noteBasicTexture;

    if (backgroundTexture.loadFromFile(kBackgroundPath + to_string(nowSelected + 1) + ".png") &&
        gameInfoTexture.loadFromFile(kGameInfoPath) &&
        judgementLineTexture.loadFromFile(kJudgementLinePath) &&
        noteRouteTexture.loadFromFile(kNoteRoutePath) &&
        noteRouteLineTexture.loadFromFile(kNoteRouteLinePath) &&
        noteBasicTexture.loadFromFile(kNoteBasicPath)) {
        // ��� �̹��� �ε� ����
    }

    RectangleShape prevButton(Vector2f(80, 80));
    prevButton.setPosition(25, 23);
    Texture prevButtonTexture;

    if (prevButtonTexture.loadFromFile("images/music_prev_btn.png")) {
        prevButton.setTexture(&prevButtonTexture);
    }

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
                    HandleMouseClick(prevButton, mousePositionF);
                }
            }
        }

        window.clear();

        // ���� ȭ�� ǥ��
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
        window.draw(prevButton);
        window.display();
    }
}

