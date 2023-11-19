// GameScreen.cpp
#include "GameScreen.h"
#include "game_functions.h"
#include "MusicSelection.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "constants.h"
#include "iostream"

using namespace sf;
using namespace std;


Font font;
bool isSPressed = false; // 다른 키에 대해서도 필요한 경우 유사한 변수 추가
GameScreen::GameScreen(sf::RenderWindow& window, int nowSelected)
    : window(window), isSPressed(false) {
    // 이미지 로드
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
        // 이미지 로드 실패 처리
    }

    // 눌린 상태의 텍스처 로드
    if (!noteRouteSTexturePressed.loadFromFile(kNoteRoutePressed)) {
        // 로드 실패 처리
    }


    // 이전 버튼 초기화
    prevButton.setSize(sf::Vector2f(80, 80));
    prevButton.setPosition(25, 23);
    sf::Texture prevButtonTexture;

    if (!font.loadFromFile(kFontPath)) {
        // 폰트 파일 경로를 설정
    }

    if (!prevButtonTexture.loadFromFile("images/music_prev_btn.png")) {
        // 텍스처 로드 실패 처리
    }

    prevButton.setTexture(&prevButtonTexture);
}
void GameScreen::update() {
    handleInput();
    // 업데이트 로직
}
void GameScreen::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            handleKeyPress(event.key.code);
        }
        else if (event.type == sf::Event::KeyReleased) {
            handleKeyRelease(event.key.code);
        }
    }
}

void GameScreen::handleKeyPress(sf::Keyboard::Key key) {
    switch (key) {
    case sf::Keyboard::S: pressS(); break;
    case sf::Keyboard::D: pressD(); break;
    case sf::Keyboard::F: pressF(); break;
    case sf::Keyboard::Space: pressSpace(); break;
    case sf::Keyboard::J: pressJ(); break;
    case sf::Keyboard::K: pressK(); break;
    case sf::Keyboard::L: pressL(); break;
        // 추가적인 키에 대한 case 추가
    }
}

void GameScreen::handleKeyRelease(sf::Keyboard::Key key) {
    switch (key) {
    case sf::Keyboard::S: releaseS(); break;
    case sf::Keyboard::D: releaseD(); break;
    case sf::Keyboard::F: releaseF(); break;
    case sf::Keyboard::Space: releaseSpace(); break;
    case sf::Keyboard::J: releaseJ(); break;
    case sf::Keyboard::K: releaseK(); break;
    case sf::Keyboard::L: releaseL(); break;
        // 추가적인 키에 대한 case 추가
    }
}
void GameScreen::pressS() {
    if (!isSPressed) {
        noteRouteSTexture = noteRouteSTexturePressed;
        isSPressed = true;
        // 키가 눌렸을 때 추가 로직
    }
}

void GameScreen::releaseS() {
    if (isSPressed) {
        noteRouteSTexture.loadFromFile(kNoteRouteSPath);
        isSPressed = false;
        // 키가 떼졌을 때 추가 로직
    }
}
void GameScreen::pressD() {
    // D 키가 눌렸을 때의 추가 로직
    if (noteRouteDTexture.loadFromFile(kNoteRoutePressed)) {
        // 성공적으로 이미지를 로드했을 때의 추가 로직
    }
    else {
        // 이미지 로드 실패 시 처리
    }
}

void GameScreen::releaseD() {
    // D 키가 떼졌을 때의 추가 로직
    if (noteRouteDTexture.loadFromFile(kNoteRouteDPath)) {
        // 성공적으로 이미지를 로드했을 때의 추가 로직
    }
    else {
        // 이미지 로드 실패 시 처리
    }
}

void GameScreen::pressF() {
    // K 키가 눌렸을 때의 추가 로직
    if (noteRouteFTexture.loadFromFile(kNoteRoutePressed)) {
        // 성공적으로 이미지를 로드했을 때의 추가 로직
    }
    else {
        // 이미지 로드 실패 시 처리
    }
}

void GameScreen::releaseF() {
    // K 키가 떼졌을 때의 추가 로직
    if (noteRouteFTexture.loadFromFile(kNoteRouteFPath)) {
        // 성공적으로 이미지를 로드했을 때의 추가 로직
    }
    else {
        // 이미지 로드 실패 시 처리
    }
}

void GameScreen::pressSpace() {
    // Space 키가 눌렸을 때의 추가 로직
    if (noteRouteSpace1Texture.loadFromFile(kNoteRoutePressed) && noteRouteSpace2Texture.loadFromFile(kNoteRoutePressed)) {
        // 성공적으로 이미지를 로드했을 때의 추가 로직
    }
    else {
        // 이미지 로드 실패 시 처리
    }
}

void GameScreen::releaseSpace() {
    // Space 키가 떼졌을 때의 추가 로직
    if (noteRouteSpace1Texture.loadFromFile(kNoteRouteSpace1Path) && noteRouteSpace2Texture.loadFromFile(kNoteRouteSpace2Path)) {
        // 성공적으로 이미지를 로드했을 때의 추가 로직
    }
    else {
        // 이미지 로드 실패 시 처리
    }
}


void GameScreen::pressJ() {
    // J 키가 눌렸을 때의 추가 로직
    if (noteRouteJTexture.loadFromFile(kNoteRoutePressed)) {
        // 성공적으로 이미지를 로드했을 때의 추가 로직
    }
    else {
        // 이미지 로드 실패 시 처리
    }
}

void GameScreen::releaseJ() {
    // J 키가 떼졌을 때의 추가 로직
    if (noteRouteJTexture.loadFromFile(kNoteRouteJPath)) {
        // 성공적으로 이미지를 로드했을 때의 추가 로직
    }
    else {
        // 이미지 로드 실패 시 처리
    }
}

void GameScreen::pressK() {
    // J 키가 눌렸을 때의 추가 로직
    if (noteRouteKTexture.loadFromFile(kNoteRoutePressed)) {
        // 성공적으로 이미지를 로드했을 때의 추가 로직
    }
    else {
        // 이미지 로드 실패 시 처리
    }
}

void GameScreen::releaseK() {
    // J 키가 떼졌을 때의 추가 로직
    if (noteRouteKTexture.loadFromFile(kNoteRouteKPath)) {
        // 성공적으로 이미지를 로드했을 때의 추가 로직
    }
    else {
        // 이미지 로드 실패 시 처리
    }
}

void GameScreen::pressL() {
    // L 키가 눌렸을 때의 추가 로직
    if (noteRouteLTexture.loadFromFile(kNoteRoutePressed)) {
        // 성공적으로 이미지를 로드했을 때의 추가 로직
    }
    else {
        // 이미지 로드 실패 시 처리
    }
}

void GameScreen::releaseL() {
    // L 키가 떼졌을 때의 추가 로직
    if (noteRouteLTexture.loadFromFile(kNoteRouteLPath)) {
        // 성공적으로 이미지를 로드했을 때의 추가 로직
        cout << "눌림";
    }
    else {
        // 이미지 로드 실패 시 처리
    }
}


void GameScreen::displayButtons() {
    window.draw(prevButton);
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
    // 판정 라인 이미지 표시
    // ...
}