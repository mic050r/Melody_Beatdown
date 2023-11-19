// KeyboardInputHandler.h
#ifndef KEYBOARD_INPUT_HANDLER_H
#define KEYBOARD_INPUT_HANDLER_H

#include <SFML/Window/Keyboard.hpp>
#include "GameScreen.h"

class KeyboardInputHandler {
public:
    KeyboardInputHandler(GameScreen& gameScreen);

    // 키가 눌렸을 때 처리하는 함수
    void handleKeyPress(sf::Keyboard::Key key);

    // 키가 떼졌을 때 처리하는 함수
    void handleKeyRelease(sf::Keyboard::Key key);

    // 다른 필요한 함수 및 멤버 추가
private:
    GameScreen& gameScreenRef;  // GameScreen에 대한 참조
};

#endif // KEYBOARD_INPUT_HANDLER_H
