// GameScreen.cpp
#include "GameScreen.h"
#include "game_functions.h"
#include "MusicSelection.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "constants.h"

using namespace sf;
using namespace std;


Font font;

GameScreen::GameScreen(sf::RenderWindow& window, int nowSelected)
    : window(window) {
    // �̹��� �ε�
    std::string backgroundImagePath = kBackgroundPathPrefix + std::to_string(nowSelected + 1) + ".png";
    if (!backgroundTexture.loadFromFile(backgroundImagePath) ||
        !gameInfoTexture.loadFromFile(kGameInfoPath) ||
        !judgementLineTexture.loadFromFile(kJudgementLinePath) ||
        !noteRouteTexture.loadFromFile(kNoteRoutePath) ||
        !noteRouteLineTexture.loadFromFile(kNoteRouteLinePath) ||
        !noteBasicTexture.loadFromFile(kNoteBasicPath)) {
        // �̹��� �ε� ���� ó��
    }

    // ���� ��ư �ʱ�ȭ
    prevButton.setSize(sf::Vector2f(80, 80));
    prevButton.setPosition(25, 23);
    sf::Texture prevButtonTexture;

    if (!font.loadFromFile(kFontPath)) {
        // ��Ʈ ���� ��θ� ����
    }

    if (!prevButtonTexture.loadFromFile("images/music_prev_btn.png")) {
        // �ؽ�ó �ε� ���� ó��
    }

    prevButton.setTexture(&prevButtonTexture);
}
void GameScreen::update() {
    // ������Ʈ ����
}

void GameScreen::render() {
    window.clear();

    displayBackground();
    displayNoteRouteLines();
    displayGameInfo();
    displayNotes();
    displayJudgementLine();
    displayButtons();

    window.display();
}

void GameScreen::displayBackground() {
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
}

void GameScreen::displayNoteRouteLines() {
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
}

void GameScreen::displayGameInfo() {
    DisplayText(window, "SPICY", font, 50, Color::White, 15, 771);
    DisplayText(window, "000000", font, 50, Color::White, 657, 774);
}

void GameScreen::displayNotes() {
    DisplayText(window, "S", font, 50, Color::White, 250, 656);
    DisplayText(window, "D", font, 50, Color::White, 384, 656);
    DisplayText(window, "F", font, 50, Color::White, 534, 656);
    DisplayText(window, "SPACE BAR", font, 40, Color::White, 630, 656);
    DisplayText(window, "J", font, 50, Color::White, 938, 656);
    DisplayText(window, "K", font, 50, Color::White, 1083, 656);
    DisplayText(window, "L", font, 50, Color::White, 1227, 656);
}

void GameScreen::displayJudgementLine() {
    // ���� ���� �̹��� ǥ��
    // ...
}

void GameScreen::displayButtons() {
    window.draw(prevButton);
    
}
