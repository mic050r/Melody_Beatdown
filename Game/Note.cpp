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

    // ��������Ʈ�� �ʱ� ��ġ�� initialX, initialY�� ����
    sprite.setPosition(initialX, initialY);
}

// Note Ŭ������ move �Լ� = ��Ʈ�� �������� �̵�
void Note::move() {
    sprite.move(0, speed);
}
