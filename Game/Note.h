// Note.h
#ifndef NOTE_H
#define NOTE_H

#include <SFML/Graphics.hpp>
#include <string>

class Note : public sf::Drawable, public sf::Transformable {
private:
    sf::Texture noteBasicTexture;
    sf::Sprite noteBasicSprite;
    int x, y;

public:
    static const int NOTE_SPEED;
    static const int SLEEP_TIME;


    // 정적 멤버 함수 추가
    static Note createNote(int x, sf::RenderWindow& window);

    Note(int x, sf::RenderWindow& window);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void drop();

    void update();
};

#endif // NOTE_H
