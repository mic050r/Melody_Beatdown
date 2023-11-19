// KeyboardInputHandler.h
#ifndef KEYBOARD_INPUT_HANDLER_H
#define KEYBOARD_INPUT_HANDLER_H

#include <SFML/Window/Keyboard.hpp>
#include "GameScreen.h"

class KeyboardInputHandler {
public:
    KeyboardInputHandler(GameScreen& gameScreen);

    // Ű�� ������ �� ó���ϴ� �Լ�
    void handleKeyPress(sf::Keyboard::Key key);

    // Ű�� ������ �� ó���ϴ� �Լ�
    void handleKeyRelease(sf::Keyboard::Key key);

    // �ٸ� �ʿ��� �Լ� �� ��� �߰�
private:
    GameScreen& gameScreenRef;  // GameScreen�� ���� ����
};

#endif // KEYBOARD_INPUT_HANDLER_H
