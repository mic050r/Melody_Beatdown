#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include <SFML/Graphics.hpp>

// 게임 화면에 배경 이미지를 표시하는 함수
void DisplayBackground(sf::RenderWindow& window, sf::Texture& backgroundTexture);

// 게임 화면에 노트를 표시하는 함수
// x, y는 노트의 위치
void DisplayNote(sf::RenderWindow& window, sf::Texture& noteTxexture, int x, int y);

// 게임 시작 처리를 담당하는 함수
void start();

// 음악을 선택하는 함수
void pick_music();

// 게임을 시작하고 게임 화면을 설정하는 함수
// nowSelected는 현재 선택한 음악
void gameStart(int nowSelected);

// 게임 화면에 텍스트를 표시하는 함수
// text는 표시할 텍스트 내용, font는 사용할 폰트, fontSize는 글꼴 크기, color는 글꼴 색상, (x, y)는 텍스트의 위치
void DisplayText(sf::RenderWindow& window, const std::string& text, const sf::Font& font, unsigned int fontSize, const sf::Color& color, float x, float y);

#endif // GAME_FUNCTIONS_H

