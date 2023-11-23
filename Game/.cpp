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
    RhythmGame rhythmGame(nowSelected);  // RhythmGame 인스턴스 생성

    rhythmGame.run();
}
