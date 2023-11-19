// KeyboardInputHandler.cpp
#include "KeyboardInputHandler.h"
#include "GameScreen.h"
KeyboardInputHandler::KeyboardInputHandler(GameScreen& gameScreen) : gameScreenRef(gameScreen) {
    // �����ڿ��� GameScreen �ν��Ͻ��� ���� ������ �ʱ�ȭ
}

void KeyboardInputHandler::handleKeyPress(sf::Keyboard::Key key){

    switch (key) {
    case sf::Keyboard::S:
        gameScreenRef.pressS();
        break;
    case sf::Keyboard::D:
        gameScreenRef.pressD();
        break;
    case sf::Keyboard::F:
        gameScreenRef.pressF(); // F Ű�� ���� ó�� �Լ� ȣ��
        break;
    case sf::Keyboard::Space:
        gameScreenRef.pressSpace(); // Space Ű�� ���� ó�� �Լ� ȣ��
        break;
    case sf::Keyboard::J:
        gameScreenRef.pressJ(); // J Ű�� ���� ó�� �Լ� ȣ��
        break;
    case sf::Keyboard::K:
        gameScreenRef.pressK(); // K Ű�� ���� ó�� �Լ� ȣ��
        break;
    case sf::Keyboard::L:
        gameScreenRef.pressL(); // L Ű�� ���� ó�� �Լ� ȣ��
        break;
        // �߰����� Ű�� ���� case �߰�
    }
}

void KeyboardInputHandler::handleKeyRelease(sf::Keyboard::Key key) {
    switch (key) {
    case sf::Keyboard::S:
        gameScreenRef.releaseS();
        break;
    case sf::Keyboard::D:
        gameScreenRef.releaseD();
        break;
        break;
    case sf::Keyboard::F:
        gameScreenRef.releaseF(); // F Ű�� ���� ó�� �Լ� ȣ��
        break;
    case sf::Keyboard::Space:
        gameScreenRef.releaseSpace(); // Space Ű�� ���� ó�� �Լ� ȣ��
        break;
    case sf::Keyboard::J:
        gameScreenRef.releaseJ(); // J Ű�� ���� ó�� �Լ� ȣ��
        break;
    case sf::Keyboard::K:
        gameScreenRef.releaseK(); // K Ű�� ���� ó�� �Լ� ȣ��
        break;
    case sf::Keyboard::L:
        gameScreenRef.releaseL(); // L Ű�� ���� ó�� �Լ� ȣ��
        break;
        // �߰����� Ű�� ���� case �߰�
    }
}
