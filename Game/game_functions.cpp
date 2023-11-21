#include "game_functions.h"
#include "MusicSelection.h"

// �ش� ��ư�� Ŭ���Ǿ����� ���θ� Ȯ���ϴ� �Լ�
bool isButtonClicked(const sf::RectangleShape& button, const sf::Vector2f& clickPosition) {
    return button.getGlobalBounds().contains(clickPosition);
}

// ���콺 Ŭ���� ó���ϰ�, ��ư�� Ŭ���Ǹ� MusicSelection�� �����ϴ� �Լ�
void HandleMouseClick(const sf::RectangleShape& button, const sf::Vector2f& clickPosition) {
    if (isButtonClicked(button, clickPosition)) {
        MusicSelection musicSelection;
        musicSelection.run();
    }
}

// ����� Ư�� â�� ǥ���ϴ� �Լ�
void DisplayBackground(sf::RenderWindow& window, sf::Texture& backgroundTexture) {
    sf::Sprite background;
    background.setTexture(backgroundTexture);
    window.draw(background);
}

// ��Ʈ�� Ư�� â�� ǥ���ϴ� �Լ�
void DisplayNote(sf::RenderWindow& window, sf::Texture& noteTexture, int x, int y) {
    sf::Sprite note;
    note.setTexture(noteTexture);
    note.setPosition(x, y);
    window.draw(note);
}

// ���� ȭ�鿡 �ؽ�Ʈ�� ǥ���ϴ� �Լ�
void DisplayText(sf::RenderWindow& window, const std::string& text, const sf::Font& font, unsigned int fontSize, const sf::Color& color, float x, float y) {
    sf::Text displayText;
    displayText.setFont(font);
    displayText.setString(text);

    displayText.setCharacterSize(fontSize);
    displayText.setFillColor(color);
    displayText.setPosition(x, y);
    window.draw(displayText);
}
