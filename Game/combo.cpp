
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

// �޺� ī���Ϳ� ���� �޺� ���¸� ��Ÿ���� ����
int combo = 0;

// ��Ȯ�� �Է��� �޾��� �� �޺� �����ϴ� �Լ�
void IncreaseCombo() {
    combo++;
}

// ȭ�鿡 ���� �޺� ���¸� ǥ���ϴ� �Լ� (SFML�� ���)
void DisplayCombo(sf::RenderWindow& window) {
    // �ؽ�Ʈ�� �޺� ǥ�ø� ���� Text ��ü ����
    sf::Text text;

    // �޺� ���� ���ڿ� ���� �� ����
    std::string comboText = "�޺�: " + std::to_string(combo);
    text.setString(comboText);

    // �ؽ�Ʈ ��ġ ����
    text.setPosition(300, 100);

    // ȭ�鿡 �޺� ǥ��
    window.draw(text);
}
