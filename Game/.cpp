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
    RhythmGame rhythmGame(nowSelected);  // RhythmGame �ν��Ͻ� ����

    rhythmGame.run();
}
