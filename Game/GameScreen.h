// GameScreen.h
#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>
#include "constants.h"

class GameScreen {
public:
    GameScreen(sf::RenderWindow& window, int nowSelected);

    void update();

    void render();

    const sf::RectangleShape& getPrevButton() const {
        return prevButton;
    }

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
private:
    sf::RenderWindow& window;
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
    sf::Texture noteRouteLineTexture;
    sf::Texture noteBasicTexture;

    sf::RectangleShape prevButton;

    void displayBackground();

    void displayNoteRouteLines();

    void displayGameInfo();

    void displayNotes();

    void displayJudgementLine();

    void displayButtons();
};

#endif // GAME_SCREEN_H
