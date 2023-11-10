#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game {
public:
    // ������
    Game();

    // �Ҹ���
    ~Game();

    // ���� ����
    void run();

private:
    // ���� �ʱ�ȭ
    void initialize();

private:
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Texture noteTexture;
    sf::Font font;
    sf::RectangleShape prevButton;

    // �ٸ� ��� ���� �� �Լ��� �ʿ信 ���� �߰��� �� �ֽ��ϴ�.
};

#endif // GAME_H
