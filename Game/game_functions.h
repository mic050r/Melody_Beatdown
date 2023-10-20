#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include <SFML/Graphics.hpp>


void DisplayBackground(sf::RenderWindow& window, sf::Texture& backgroundTexture);
void DisplayNote(sf::RenderWindow& window, sf::Texture& noteTexture, int x, int y);
void start();
void pick_music();
void gameStart(int nowSelected);
void DisplayText(sf::RenderWindow& window, const std::string& text, const sf::Font& font, unsigned int fontSize, const sf::Color& color, float x, float y);

#endif // GAME_FUNCTIONS_H
