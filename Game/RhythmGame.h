#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Note.h"

class RhythmGame {
public:
    RhythmGame();
    void run();

private:
    sf::RenderWindow window;
    sf::Music music;
    sf::Clock clock;
    sf::Clock gameClock;
    sf::Time elapsed;
    sf::Time noteSpawnTime;
    sf::Time gameDuration;

    std::vector<Note*> notes;
    float noteSpeed;

    std::vector<sf::Text> menu;
    sf::Font font;

    sf::RectangleShape separatorLine;

    sf::Text songTitleText;
    sf::Text comboText;

    int combo;
    float judgmentRange;
    std::string judgment;

    void handleNoteInput(float judgmentRange);
    void drawNotes();
    void drawMenu();
    void drawTexts();
};
