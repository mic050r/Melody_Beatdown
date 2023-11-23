#include "game_functions.h"
#include "GameFunctions.h"
#include "MusicSelection.h"
#include "constants.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "RhythmGame.h"
using namespace sf;
using namespace std;


void gameStart(int nowSelected) {
    RenderWindow window(VideoMode(1500, 843), "Game");

    RhythmGame rhythmGame;  // RhythmGame 인스턴스 생성
    rhythmGame.run();
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    

                    Vector2i mousePosition = Mouse::getPosition(window);
                    Vector2f mousePositionF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
                    //HandleMouseClick(gameScreen.getPrevButton(), mousePositionF);
                }
            }
        }

    }
}
