#pragma once

#include <SFML/Graphics.hpp>

class StartScreen {
private:
    sf::RenderWindow window;        // 게임 창 객체
    sf::Texture backgroundTexture;  // 게임 시작 화면 배경 이미지 텍스처

public:
    StartScreen();
    void run();
};
