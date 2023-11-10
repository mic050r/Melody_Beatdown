#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game {
public:
    // 생성자
    Game();

    // 소멸자
    ~Game();

    // 게임 실행
    void run();

private:
    // 게임 초기화
    void initialize();

private:
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Texture noteTexture;
    sf::Font font;
    sf::RectangleShape prevButton;

    // 다른 멤버 변수 및 함수를 필요에 따라 추가할 수 있습니다.
};

#endif // GAME_H
