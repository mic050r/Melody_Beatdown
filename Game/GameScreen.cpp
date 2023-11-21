// GameScreen.cpp
#include "GameScreen.h"
#include "game_functions.h"
#include "MusicSelection.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "constants.h"
#include <iostream>

using namespace sf;
using namespace std;

Font font;
string titleName;

GameScreen::GameScreen(sf::RenderWindow& window, int nowSelected)
    : window(window), isSPressed(false), nowSelected(nowSelected) {
    loadTextures(); // �̹��� �ε�
    initPrevButton(); // ���� ��ư �ʱ�ȭ
    musicInfoList = {
        { "music/Aespa-Spicy.wav", sf::Texture(), std::make_shared<sf::Music>() },
        { "music/Aespa-Hold-On-Tight.wav", sf::Texture(), std::make_shared<sf::Music>() },
        { "music/Aespa-Better-Things.wav", sf::Texture(), std::make_shared<sf::Music>() }
    };

    // �ؽ�ó �ʱ�ȭ
    musicTextures = { sf::Texture(), sf::Texture(), sf::Texture() };

    // �̹��� �ؽ�ó �̸� �ε�
    for (size_t i = 0; i < musicTextures.size(); ++i) {
        if (musicTextures[i].loadFromFile("images/music" + std::to_string(i + 1) + ".png")) {
            // �ؽ�ó �ε� ����
        }
    }
    // ���� �ε� �� ���
    for (size_t i = 0; i < musicInfoList.size(); ++i) {
        if (musicInfoList[i].music->openFromFile(musicInfoList[i].path)) {
            musicInfoList[i].music->stop();
        }
    }

    // ���õ� ���� ���
    if (nowSelected >= 0 && nowSelected < musicInfoList.size()) {
        musicInfoList[nowSelected].music->play();
    }

    switch (nowSelected) {
    case 0:
        titleName = "Spicy";
        break;
    case 1:
        titleName = "Hold On Tight";
        break;
    case 2:
        titleName = "Better Things";
    }
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
    if (key == sf::Keyboard::S) {
        pressS();
        cout << "s����";
    }
    else if (key == sf::Keyboard::D) {
        pressD(); cout << "d����";
    }
    else if (key == sf::Keyboard::F) {
        pressF(); cout << "f����";
    }
    else if (key == sf::Keyboard::Space) {
        pressSpace(); cout << "sacd����";
    }
    else if (key == sf::Keyboard::J) {
        pressJ(); cout << "j����";
    }
    else if (key == sf::Keyboard::K) {
        pressK(); cout << "k����";
    }
    else if (key == sf::Keyboard::L) {
        pressL(); cout << "l����";
    }
}

void GameScreen::handleKeyRelease(sf::Keyboard::Key key) {
    if (key == sf::Keyboard::S) {
        releaseS();
    }
    else if (key == sf::Keyboard::D) {
        releaseD();
    }
    else if (key == sf::Keyboard::F) {
        releaseF();
    }
    else if (key == sf::Keyboard::Space) {
        releaseSpace();
    }
    else if (key == sf::Keyboard::J) {
        releaseJ();
    }
    else if (key == sf::Keyboard::K) {
        releaseK();
    }
    else if (key == sf::Keyboard::L) {
        releaseL();
    }
    // �߰����� Ű�� ���� case �߰�
}



void GameScreen::update() {
    handleInput();
    // ������Ʈ ����
}

void GameScreen::pressS() {
    noteRouteSTexture = noteRoutePressedTexture;
    isSPressed = true;
    // Ű�� ������ �� �߰� ����
}

void GameScreen::releaseS() {

    isSPressed = false;
    // Ű�� ������ �� �߰� ����
}

void GameScreen::pressD() {
    noteRouteDTexture = noteRoutePressedTexture;
    isSPressed = true;
}

void GameScreen::releaseD() {
    
    isSPressed = false;
}

void GameScreen::pressF() {
    noteRouteFTexture = noteRoutePressedTexture;
    isSPressed = true;
}

void GameScreen::releaseF() {
    isSPressed = false;
}

void GameScreen::pressSpace() {
    noteRouteSpace1Texture = noteRoutePressedTexture;
    isSPressed = true;
}

void GameScreen::releaseSpace() {
    isSPressed = false;
}

void GameScreen::pressJ() {
    noteRouteJTexture = noteRoutePressedTexture;
    isSPressed = true;
}

void GameScreen::releaseJ() {
    isSPressed = false;
}

void GameScreen::pressK() {
    noteRouteKTexture = noteRoutePressedTexture;
    isSPressed = true;
}

void GameScreen::releaseK() {
    isSPressed = false;
}

void GameScreen::pressL() {
    noteRouteLTexture = noteRoutePressedTexture;
    isSPressed = true;
}

void GameScreen::releaseL() {
    isSPressed = false;
}

void GameScreen::initPrevButton() {
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

void GameScreen::displayButtons() {
    window.draw(prevButton);
}

void GameScreen::render() {
    window.clear();

    displayBackground();
    //displayNoteRouteLines();
    displayGameInfo();
    displayNotes();
    displayJudgementLine();
    displayButtons();
    initNotes();
    updateNotes();
    drawNotes();

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
    DisplayNote(window, noteRouteSTexture, 190, 0);
    DisplayNote(window, noteRouteDTexture, 330, 0);
    DisplayNote(window, noteRouteFTexture, 470, 0);
    DisplayNote(window, noteRouteSpace1Texture, 610, 0);
    DisplayNote(window, noteRouteSpace2Texture, 750, 0);
    DisplayNote(window, noteRouteJTexture, 890, 0);
    DisplayNote(window, noteRouteKTexture, 1030, 0);
    DisplayNote(window, noteRouteLTexture, 1170, 0);
    DisplayNote(window, gameInfoTexture, 0, 763);
    DisplayNote(window, judgementLineTexture, 0, 660);
}

void GameScreen::initNotes() {
    // ��Ʈ �ʱ�ȭ ����
    notes.push_back(Note::createNote(194));
    /*notes.push_back(Note::createNote(335));
    notes.push_back(Note::createNote(474));
    notes.push_back(Note::createNote(681));
    notes.push_back(Note::createNote(888));
    notes.push_back(Note::createNote(1029));
    notes.push_back(Note::createNote(1172));*/
}


void GameScreen::updateNotes() {
    // ��Ʈ ������Ʈ ����
    for (auto& note : notes) {
        note.update();
    }
}

void GameScreen::drawNotes() {
    // ��Ʈ�� ȭ�鿡 �׸��� ����
    for (const auto& note : notes) {
        window.draw(note);
    }
}

void GameScreen::displayGameInfo() {
    DisplayText(window, titleName, font, 50, Color::White, 15, 771);
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

void GameScreen::loadTextures() {
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
        !noteRoutePressedTexture.loadFromFile(kNoteRoutePressed) ||
        !noteRouteLineTexture.loadFromFile(kNoteRouteLinePath) ||
        !noteBasicTexture.loadFromFile(kNoteBasicPath)) {
        // �̹��� �ε� ���� ó��
    }


   
}