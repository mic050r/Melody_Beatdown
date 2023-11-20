// GameScreen.h
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "constants.h"

class GameScreen {
public:
    GameScreen(sf::RenderWindow& window, int nowSelected);
    void update();
    void render();
    const sf::RectangleShape& getPrevButton() const {
        return prevButton;
    }
private:
    sf::RenderWindow& window;
    bool isSPressed;

    sf::Texture backgroundTexture;
    sf::Texture gameInfoTexture;
    sf::Texture judgementLineTexture;
    sf::Texture noteRouteSTexture;
    sf::Texture noteRouteDTexture;
    sf::Texture noteRouteFTexture;
    sf::Texture noteRouteSpace1Texture;
    sf::Texture noteRouteSpace2Texture;
    sf::Texture noteRouteJTexture;
    sf::Texture noteRouteKTexture;
    sf::Texture noteRouteLTexture;
    sf::Texture noteRoutePressedTexture;
    sf::Texture noteRouteLineTexture;
    sf::Texture noteBasicTexture;
    void loadTextures(); // 이 함수를 추가하여 텍스처를 로드하도록 함
    int nowSelected; // nowSelected를 멤버 변수로 추가
    sf::RectangleShape prevButton;
    sf::Font font;

    void handleInput();
    void handleKeyPress(sf::Keyboard::Key key);
    void handleKeyRelease(sf::Keyboard::Key key);

    void pressKey(sf::Texture& texture, const std::string& path);
    void releaseKey(sf::Texture& texture, const std::string& path);
    void pressKeyDual(sf::Texture& texture1, sf::Texture& texture2, const std::string& path1, const std::string& path2);
    void releaseKeyDual(sf::Texture& texture1, sf::Texture& texture2, const std::string& path1, const std::string& path2);

    void pressS();
    void releaseS();
    void pressD();
    void releaseD();
    void pressF();
    void releaseF();
    void pressSpace();
    void releaseSpace();
    void pressJ();
    void releaseJ();
    void pressK();
    void releaseK();
    void pressL();
    void releaseL();

    void initPrevButton();
    void displayButtons();
    void displayBackground();
    void displayNoteRouteLines();
    void displayGameInfo();
    void displayNotes();
    void displayJudgementLine();

    
};
