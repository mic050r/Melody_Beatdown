#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include <SFML/Graphics.hpp>

// ���� ȭ�鿡 ��� �̹����� ǥ���ϴ� �Լ�
void DisplayBackground(sf::RenderWindow& window, sf::Texture& backgroundTexture);

// ���� ȭ�鿡 ��Ʈ�� ǥ���ϴ� �Լ�
// x, y�� ��Ʈ�� ��ġ
void DisplayNote(sf::RenderWindow& window, sf::Texture& noteTxexture, int x, int y);

// ���� ���� ó���� ����ϴ� �Լ�
void start();

// ������ �����ϴ� �Լ�
void pick_music();

// ������ �����ϰ� ���� ȭ���� �����ϴ� �Լ�
// nowSelected�� ���� ������ ����
void gameStart(int nowSelected);

// ���� ȭ�鿡 �ؽ�Ʈ�� ǥ���ϴ� �Լ�
// text�� ǥ���� �ؽ�Ʈ ����, font�� ����� ��Ʈ, fontSize�� �۲� ũ��, color�� �۲� ����, (x, y)�� �ؽ�Ʈ�� ��ġ
void DisplayText(sf::RenderWindow& window, const std::string& text, const sf::Font& font, unsigned int fontSize, const sf::Color& color, float x, float y);

#endif // GAME_FUNCTIONS_H

