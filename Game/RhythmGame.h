#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Note.h"
#include <string>

class RhythmGame {
 public:
        RhythmGame(int nowSelected);
        void run();
        std::string titleName;
        std::string song;
       
private:
    sf::RenderWindow window;
    sf::Music music;
    sf::Clock clock;
    sf::Clock gameClock;
    sf::Time elapsed;
    sf::Time noteSpawnTime;
    sf::Time gameDuration;
    sf::RectangleShape prevButton;

    sf::Text comboText;

    sf::Texture backgroundTexture;
    std::vector<Note*> notes;
    float noteSpeed;
    int nowSelected;

    std::vector<sf::Text> menu;
    sf::Font font;

    sf::RectangleShape separatorLine;

    int combo;
    int PERFECT;
    int GOOD;
    int MISS;
    float judgmentRange;
    std::string judgment;

    void handleNoteInput(float judgmentRange);
    void drawNotes();
    void drawMenu();
    void drawTexts();
    void displayButtons();
};
