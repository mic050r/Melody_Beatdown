// ResultScreen.h

#ifndef RESULT_SCREEN_H
#define RESULT_SCREEN_H

#include <SFML/Graphics.hpp>

class ResultScreen {
public:
    ResultScreen(int combo, int PERFECT, int GOOD, int MISS);
    int combo;
    int PERFECT;
    int GOOD;
    int MISS;
    void run();

private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text comboText;
    sf::Text FText;
    sf::Text GText;
    sf::Text MText;

    sf::Texture backgroundTexture;
    sf::Texture retryTexture;

    sf::RectangleShape retry;
};

#endif // RESULT_SCREEN_H
