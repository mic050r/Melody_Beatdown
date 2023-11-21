#include "game_functions.h"
#include "MusicSelection.h"
#include <iostream>

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

void DisplayButton(sf::RenderWindow& window, sf::RectangleShape& button, const std::string& path, sf::Texture& buttonTexture, float x, float y, float width, float height) {
    button.setSize(sf::Vector2f(width, height));  // 버튼 크기 설정
    button.setPosition(x, y);  // 버튼 위치 설정

    if (buttonTexture.loadFromFile(path)) {
        button.setTexture(&buttonTexture);
    }
    else {
        std::cout << "Error loading button texture. Using default texture.\n";
        // 기본 이미지 설정 또는 다른 처리
    }

    window.draw(button);  // 화면에 버튼 표시
}