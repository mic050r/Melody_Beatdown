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

private:
    sf::RenderWindow& window;
    sf::Texture backgroundTexture;
    sf::Texture gameInfoTexture;
    sf::Texture judgementLineTexture;
    sf::Texture noteRouteTexture;
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
