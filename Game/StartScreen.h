#pragma once

#include <SFML/Graphics.hpp>

class StartScreen {
private:
    sf::RenderWindow window;        // ���� â ��ü
    sf::Texture backgroundTexture;  // ���� ���� ȭ�� ��� �̹��� �ؽ�ó

public:
    StartScreen();
    void run();
};
