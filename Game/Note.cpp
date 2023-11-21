// Note.cpp
#include "Note.h"
#include "game_functions.h"
#include "constants.h"
#include <iostream>

const int Note::NOTE_SPEED = 2;
const int Note::SLEEP_TIME = 1000;

Note::Note(int x, sf::RenderWindow& window) : x(x), y(580 - SLEEP_TIME * NOTE_SPEED) {
    // noteBasicTexture 파일로부터 로드
    if (!noteBasicTexture.loadFromFile(kNoteBasicPath)) {
        std::cout << "noteBasic 텍스처 로드 실패.\n";
    }
    DisplayNote2(window, noteBasicSprite, noteBasicTexture, static_cast<float>(x), static_cast<float>(y));
    
}

void Note::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(noteBasicSprite, states);
}

void Note::drop() {
    y += NOTE_SPEED;
    noteBasicSprite.setPosition(static_cast<float>(x), static_cast<float>(y));
}

void Note::update() {
    drop();
}

Note Note::createNote(int x, sf::RenderWindow& window) {
    return Note(x, window);
}
