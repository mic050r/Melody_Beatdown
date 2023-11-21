#include "game_functions.h"
#include "MusicSelection.h"

// 해당 버튼이 클릭되었는지 여부를 확인하는 함수
bool isButtonClicked(const sf::RectangleShape& button, const sf::Vector2f& clickPosition) {
    return button.getGlobalBounds().contains(clickPosition);
}

// 마우스 클릭을 처리하고, 버튼이 클릭되면 MusicSelection을 실행하는 함수
void HandleMouseClick(const sf::RectangleShape& button, const sf::Vector2f& clickPosition) {
    if (isButtonClicked(button, clickPosition)) {
        MusicSelection musicSelection;
        musicSelection.run();
    }
}

// 배경을 특정 창에 표시하는 함수
void DisplayBackground(sf::RenderWindow& window, sf::Texture& backgroundTexture) {
    sf::Sprite background;
    background.setTexture(backgroundTexture);
    window.draw(background);
}

// 노트를 특정 창에 표시하는 함수
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
