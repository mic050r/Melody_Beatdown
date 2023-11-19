// KeyboardInputHandler.cpp
#include "KeyboardInputHandler.h"
#include "GameScreen.h"
KeyboardInputHandler::KeyboardInputHandler(GameScreen& gameScreen) : gameScreenRef(gameScreen) {
    // 생성자에서 GameScreen 인스턴스에 대한 참조를 초기화
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
        gameScreenRef.pressF(); // F 키에 대한 처리 함수 호출
        break;
    case sf::Keyboard::Space:
        gameScreenRef.pressSpace(); // Space 키에 대한 처리 함수 호출
        break;
    case sf::Keyboard::J:
        gameScreenRef.pressJ(); // J 키에 대한 처리 함수 호출
        break;
    case sf::Keyboard::K:
        gameScreenRef.pressK(); // K 키에 대한 처리 함수 호출
        break;
    case sf::Keyboard::L:
        gameScreenRef.pressL(); // L 키에 대한 처리 함수 호출
        break;
        // 추가적인 키에 대한 case 추가
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
        gameScreenRef.releaseF(); // F 키에 대한 처리 함수 호출
        break;
    case sf::Keyboard::Space:
        gameScreenRef.releaseSpace(); // Space 키에 대한 처리 함수 호출
        break;
    case sf::Keyboard::J:
        gameScreenRef.releaseJ(); // J 키에 대한 처리 함수 호출
        break;
    case sf::Keyboard::K:
        gameScreenRef.releaseK(); // K 키에 대한 처리 함수 호출
        break;
    case sf::Keyboard::L:
        gameScreenRef.releaseL(); // L 키에 대한 처리 함수 호출
        break;
        // 추가적인 키에 대한 case 추가
    }
}
