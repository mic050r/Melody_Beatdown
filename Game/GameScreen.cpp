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
        !noteRouteSTexture.loadFromFile(kNoteRouteSPath) ||
        !noteRouteDTexture.loadFromFile(kNoteRouteDPath) ||
        !noteRouteFTexture.loadFromFile(kNoteRouteFPath) ||
        !noteRouteSpace1Texture.loadFromFile(kNoteRouteSpace1Path) ||
        !noteRouteSpace2Texture.loadFromFile(kNoteRouteSpace2Path) ||
        !noteRouteJTexture.loadFromFile(kNoteRouteJPath) ||
        !noteRouteKTexture.loadFromFile(kNoteRouteKPath) ||
        !noteRouteLTexture.loadFromFile(kNoteRouteLPath) ||
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
    DisplayNote(window, noteRouteSTexture, 190, 0);
    DisplayNote(window, noteRouteDTexture, 330, 0);
    DisplayNote(window, noteRouteFTexture, 470, 0);
    DisplayNote(window, noteRouteSpace1Texture, 610, 0);
    DisplayNote(window, noteRouteSpace2Texture, 750, 0);
    DisplayNote(window, noteRouteJTexture, 890, 0);
    DisplayNote(window, noteRouteKTexture, 1030, 0);
    DisplayNote(window, noteRouteLTexture, 1170, 0);
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
void GameScreen::pressS() {
    // S Ű�� ������ ���� �߰� ����
    if (noteRouteSTexture.loadFromFile(kNoteRoutePressed)) {
        // ���������� �̹����� �ε����� ���� �߰� ����
    }
    else {
        // �̹��� �ε� ���� �� ó��
    }
}

void GameScreen::releaseS() {
    // S Ű�� ������ ���� �߰� ����
    if (noteRouteSTexture.loadFromFile(kNoteRouteSPath)) {
        // ���������� �̹����� �ε����� ���� �߰� ����
    }
    else {
        // �̹��� �ε� ���� �� ó��
    }
}

void GameScreen::pressD() {
    // D Ű�� ������ ���� �߰� ����
    if (noteRouteDTexture.loadFromFile(kNoteRoutePressed)) {
        // ���������� �̹����� �ε����� ���� �߰� ����
    }
    else {
        // �̹��� �ε� ���� �� ó��
    }
}

void GameScreen::releaseD() {
    // D Ű�� ������ ���� �߰� ����
    if (noteRouteDTexture.loadFromFile(kNoteRouteDPath)) {
        // ���������� �̹����� �ε����� ���� �߰� ����
    }
    else {
        // �̹��� �ε� ���� �� ó��
    }
}

void GameScreen::pressF() {
    // K Ű�� ������ ���� �߰� ����
    if (noteRouteFTexture.loadFromFile(kNoteRoutePressed)) {
        // ���������� �̹����� �ε����� ���� �߰� ����
    }
    else {
        // �̹��� �ε� ���� �� ó��
    }
}

void GameScreen::releaseF() {
    // K Ű�� ������ ���� �߰� ����
    if (noteRouteFTexture.loadFromFile(kNoteRouteFPath)) {
        // ���������� �̹����� �ε����� ���� �߰� ����
    }
    else {
        // �̹��� �ε� ���� �� ó��
    }
}

void GameScreen::pressSpace() {
    // Space Ű�� ������ ���� �߰� ����
    if (noteRouteSpace1Texture.loadFromFile(kNoteRoutePressed) && noteRouteSpace2Texture.loadFromFile(kNoteRoutePressed)) {
        // ���������� �̹����� �ε����� ���� �߰� ����
    }
    else {
        // �̹��� �ε� ���� �� ó��
    }
}

void GameScreen::releaseSpace() {
    // Space Ű�� ������ ���� �߰� ����
    if (noteRouteSpace1Texture.loadFromFile(kNoteRouteSpace1Path) && noteRouteSpace2Texture.loadFromFile(kNoteRouteSpace2Path)) {
        // ���������� �̹����� �ε����� ���� �߰� ����
    }
    else {
        // �̹��� �ε� ���� �� ó��
    }
}


void GameScreen::pressJ() {
    // J Ű�� ������ ���� �߰� ����
    if (noteRouteJTexture.loadFromFile(kNoteRoutePressed)) {
        // ���������� �̹����� �ε����� ���� �߰� ����
    }
    else {
        // �̹��� �ε� ���� �� ó��
    }
}

void GameScreen::releaseJ() {
    // J Ű�� ������ ���� �߰� ����
    if (noteRouteJTexture.loadFromFile(kNoteRouteJPath)) {
        // ���������� �̹����� �ε����� ���� �߰� ����
    }
    else {
        // �̹��� �ε� ���� �� ó��
    }
}

void GameScreen::pressK() {
    // J Ű�� ������ ���� �߰� ����
    if (noteRouteKTexture.loadFromFile(kNoteRoutePressed)) {
        // ���������� �̹����� �ε����� ���� �߰� ����
    }
    else {
        // �̹��� �ε� ���� �� ó��
    }
}

void GameScreen::releaseK() {
    // J Ű�� ������ ���� �߰� ����
    if (noteRouteKTexture.loadFromFile(kNoteRouteKPath)) {
        // ���������� �̹����� �ε����� ���� �߰� ����
    }
    else {
        // �̹��� �ε� ���� �� ó��
    }
}

void GameScreen::pressL() {
    // L Ű�� ������ ���� �߰� ����
    if (noteRouteLTexture.loadFromFile(kNoteRoutePressed)) {
        // ���������� �̹����� �ε����� ���� �߰� ����
    }
    else {
        // �̹��� �ε� ���� �� ó��
    }
}

void GameScreen::releaseL() {
    // L Ű�� ������ ���� �߰� ����
    if (noteRouteLTexture.loadFromFile(kNoteRouteLPath)) {
        // ���������� �̹����� �ε����� ���� �߰� ����
    }
    else {
        // �̹��� �ε� ���� �� ó��
    }
}

void GameScreen::displayButtons() {
    window.draw(prevButton);
}
