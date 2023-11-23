#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include <SFML/Graphics.hpp>

// 게임 화면에 배경 이미지를 표시하는 함수
void DisplayBackground(sf::RenderWindow& window, sf::Texture& backgroundTexture);

// 게임 화면에 노트를 표시하는 함수
// x, y는 노트의 위치
void DisplayNote(sf::RenderWindow& window, sf::Texture& noteTexture, int x, int y);
void DisplayNote2(sf::RenderWindow& window, sf::Sprite& note, sf::Texture& noteTexture, int x, int y);
void DisplayNote3(sf::RenderWindow& window, sf::Sprite& sprite, sf::Texture& texture, int x, int y);
// 게임을 시작하고 게임 화면을 설정하는 함수
// nowSelected는 현재 선택한 음악
void gameStart(int nowSelected);

// 게임 화면에 텍스트를 표시하는 함수
// text는 표시할 텍스트 내용, font는 사용할 폰트, fontSize는 글꼴 크기, color는 글꼴 색상, (x, y)는 텍스트의 위치
void DisplayText(sf::RenderWindow& window, const std::string& text, const sf::Font& font, unsigned int fontSize, const sf::Color& color, float x, float y);

// 버튼을 만들고 이미지를 표시하는 함수
// x, y는 버튼의 위치, buttonText는 버튼 위에 표시할 텍스트 내용, buttonTexture는 버튼의 배경 이미지
void DisplayButton(sf::RenderWindow& window, sf::RectangleShape& button, const std::string& path, sf::Texture& buttonTexture, float x, float y, float width, float height);
// 마우스 클릭 여부를 확인하는 함수
// button은 클릭을 확인할 버튼, clickPosition은 마우스 클릭 위치
bool isButtonClicked(const sf::RectangleShape& button, const sf::Vector2f& clickPosition);

// 마우스 클릭 이벤트를 처리하는 함수
// button은 클릭된 버튼, clickPosition은 마우스 클릭 위치
void HandleMouseClick(const sf::RectangleShape& button, const sf::Vector2f& clickPosition);

#endif // GAME_FUNCTIONS_H
