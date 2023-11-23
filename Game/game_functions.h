#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include <SFML/Graphics.hpp>

// ���� ȭ�鿡 ��� �̹����� ǥ���ϴ� �Լ�
void DisplayBackground(sf::RenderWindow& window, sf::Texture& backgroundTexture);

// ���� ȭ�鿡 ��Ʈ�� ǥ���ϴ� �Լ�
// x, y�� ��Ʈ�� ��ġ
void DisplayNote(sf::RenderWindow& window, sf::Texture& noteTexture, int x, int y);
void DisplayNote2(sf::RenderWindow& window, sf::Sprite& note, sf::Texture& noteTexture, int x, int y);
void DisplayNote3(sf::RenderWindow& window, sf::Sprite& sprite, sf::Texture& texture, int x, int y);
// ������ �����ϰ� ���� ȭ���� �����ϴ� �Լ�
// nowSelected�� ���� ������ ����
void gameStart(int nowSelected);

// ���� ȭ�鿡 �ؽ�Ʈ�� ǥ���ϴ� �Լ�
// text�� ǥ���� �ؽ�Ʈ ����, font�� ����� ��Ʈ, fontSize�� �۲� ũ��, color�� �۲� ����, (x, y)�� �ؽ�Ʈ�� ��ġ
void DisplayText(sf::RenderWindow& window, const std::string& text, const sf::Font& font, unsigned int fontSize, const sf::Color& color, float x, float y);

// ��ư�� ����� �̹����� ǥ���ϴ� �Լ�
// x, y�� ��ư�� ��ġ, buttonText�� ��ư ���� ǥ���� �ؽ�Ʈ ����, buttonTexture�� ��ư�� ��� �̹���
void DisplayButton(sf::RenderWindow& window, sf::RectangleShape& button, const std::string& path, sf::Texture& buttonTexture, float x, float y, float width, float height);
// ���콺 Ŭ�� ���θ� Ȯ���ϴ� �Լ�
// button�� Ŭ���� Ȯ���� ��ư, clickPosition�� ���콺 Ŭ�� ��ġ
bool isButtonClicked(const sf::RectangleShape& button, const sf::Vector2f& clickPosition);

// ���콺 Ŭ�� �̺�Ʈ�� ó���ϴ� �Լ�
// button�� Ŭ���� ��ư, clickPosition�� ���콺 Ŭ�� ��ġ
void HandleMouseClick(const sf::RectangleShape& button, const sf::Vector2f& clickPosition);

#endif // GAME_FUNCTIONS_H
