#include "Note.h"

Note::Note(float speed, const std::string& imagePath, float initialX, float initialY)
    : speed(speed) {
    if (!texture.loadFromFile(imagePath)) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(50.f / texture.getSize().x, 30.f / texture.getSize().y));
    sprite.setPosition(initialX, initialY);
}

void Note::move() {
    sprite.move(0, speed);
}
