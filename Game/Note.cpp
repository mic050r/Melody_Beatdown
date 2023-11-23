#include "Note.h"

// Note Ŭ������ ������
Note::Note(float speed, const std::string& imagePath, float initialX, float initialY)
    : speed(speed) {  // speed�� ��� ������ �����մϴ�.

    // �̹����� �ε�
    if (!texture.loadFromFile(imagePath)) {
        std::cerr << "Failed to load texture" << std::endl;
    }

    // sprite�� �ε��� �ؽ�ó�� ����
    sprite.setTexture(texture);

    // ��������Ʈ�� ũ�⸦ �̹����� ���� ũ�� ��� 50x30�� ������ ����
    sprite.setScale(sf::Vector2f(50.f / texture.getSize().x, 30.f / texture.getSize().y));

    // ��������Ʈ�� �ʱ� ��ġ�� initialX, initialY�� ����
    sprite.setPosition(initialX, initialY);
}

// Note Ŭ������ move �Լ� = ��Ʈ�� �������� �̵�
void Note::move() {
    sprite.move(0, speed);
}
