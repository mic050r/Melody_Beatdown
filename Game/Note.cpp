// Note.cpp

#include "Note.h"
#include <iostream>
#include "constants.h"

Note::Note(int x) : x(x), y(580 - SLEEP_TIME * NOTE_SPEED) {
    // noteBasicTexture ���Ϸκ��� �ε�
    if (!noteBasicTexture.loadFromFile(kNoteBasicPath)) {
        // �ؽ�ó �ε忡 ������ ��� ���� ó��
        std::cerr << "noteBasic �ؽ�ó �ε� ����.\n";
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
