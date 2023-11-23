#include "Note.h"

// Note 클래스의 생성자
Note::Note(float speed, const std::string& imagePath, float initialX, float initialY)
    : speed(speed) {  // speed를 멤버 변수에 설정합니다.

    // 이미지를 로드
    if (!texture.loadFromFile(imagePath)) {
        std::cerr << "Failed to load texture" << std::endl;
    }

    // sprite에 로드한 텍스처를 설정
    sprite.setTexture(texture);

    // 스프라이트의 크기를 이미지의 원본 크기 대비 50x30의 비율로 조정
    sprite.setScale(sf::Vector2f(50.f / texture.getSize().x, 30.f / texture.getSize().y));

    // 스프라이트의 초기 위치를 initialX, initialY로 설정
    sprite.setPosition(initialX, initialY);
}

// Note 클래스의 move 함수 = 노트를 수직으로 이동
void Note::move() {
    sprite.move(0, speed);
}
