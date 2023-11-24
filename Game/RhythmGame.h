#pragma once

#include "Note.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

class RhythmGame {
 public:

     // 판정 결과를 나타내는 enum 정의
    /* enum class Judgment {
         PERFECT,
         GOOD,
         MISS
     };*/

    RhythmGame(int nowSelected);
    void run();
    std::string titleName;
    std::string song;
    std::string backgroundImagePath;
       
private:
    sf::RenderWindow window;
    sf::Music music;
    sf::Clock clock;
    sf::Clock gameClock;
    sf::Time elapsed;
    sf::Time noteSpawnTime;
    sf::Time gameDuration;
    sf::RectangleShape prevButton;
    sf::RectangleShape separatorLine;

    sf::Texture backgroundTexture;
    sf::Text comboText;
    sf::Font font;

    std::vector<Note*> notes;
    std::vector<sf::RectangleShape> menuImages;
   
    std::string judgment;

    int nowSelected;
    int combo;
    int PERFECT;
    int GOOD;
    int MISS;
    float judgmentRange;
    float noteSpeed;

    void handleNoteInput(float judgmentRange);
    void drawNotes();
    void drawMenu();
    void drawTexts();
    void displayButtons();
};
