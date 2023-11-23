#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Note {
public:
    sf::Sprite sprite;
    sf::Texture texture;
    float speed;

    Note(float speed, const std::string& imagePath, float initialX, float initialY);
    void move();
};
