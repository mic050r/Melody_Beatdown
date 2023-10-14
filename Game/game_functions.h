#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include <SFML/Graphics.hpp>

void DisplayBackground(sf::RenderWindow& window, sf::Texture& backgroundTexture);
void DisplayNote(sf::RenderWindow& window, sf::Texture& noteTexture, int x, int y);

#endif // GAME_FUNCTIONS_H
