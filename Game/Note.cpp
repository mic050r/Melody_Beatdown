// Note.cpp

#include "Note.h"
#include <iostream>
#include "constants.h"

Note::Note(int x) : x(x), y(580 - SLEEP_TIME * NOTE_SPEED) {
    // noteBasicTexture 파일로부터 로드
    if (!noteBasicTexture.loadFromFile(kNoteBasicPath)) {
        // 텍스처 로드에 실패한 경우 오류 처리
        std::cerr << "noteBasic 텍스처 로드 실패.\n";
    }

    noteBasicSprite.setTexture(noteBasicTexture);
    noteBasicSprite.setPosition(static_cast<float>(x), static_cast<float>(y));
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
