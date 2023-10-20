#include "game_functions.h"

void DisplayBackground(sf::RenderWindow& window, sf::Texture& backgroundTexture) {
    sf::Sprite background;
    background.setTexture(backgroundTexture);
    window.draw(background);
}

void DisplayNote(sf::RenderWindow& window, sf::Texture& noteTexture, int x, int y) {
    sf::Sprite note;
    note.setTexture(noteTexture);
    note.setPosition(x, y);
    window.draw(note);
}

// 게임 화면에 텍스트를 표시하는 함수
void DisplayText(sf::RenderWindow& window, const std::string& text, const sf::Font& font, unsigned int fontSize, const sf::Color& color, float x, float y) {
    sf::Text displayText;
    displayText.setFont(font);
    displayText.setString(text);

    displayText.setCharacterSize(fontSize);
    displayText.setFillColor(color);
    displayText.setPosition(x, y);
    window.draw(displayText);
}