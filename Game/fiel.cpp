#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <bzlib.h>

using namespace sf;
using namespace std;

// ���� �Ӱ谪 ��� ����
const int GREAT_THRESHOLD = 50; // �ְ� ���� �Ӱ谪
const int GOOD_THRESHOLD = 100; // ���� ���� �Ӱ谪

// ��Ʈ ������ ����ϴ� �Լ�
string CalculateNoteJudgment(int noteTime, int inputTime) {
    int timeDifference = abs(noteTime - inputTime);

    if (timeDifference < GREAT_THRESHOLD) {
        return "�ְ�"; // �ְ� ����
    }
    else if (timeDifference < GOOD_THRESHOLD) {
        return "����"; // ���� ����
    }
    else {
        return "����"; // ���� ����
    }
}

// SFML�� ����Ͽ� ȭ�鿡 ������ ǥ���ϴ� �Լ�
void DisplayJudgment(RenderWindow& window, const string& judgment) {
    /*Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cerr << "��Ʈ�� ã�� �� �����ϴ�!" << endl;
        return;
    }*/

    Text text;
    //text.setFont(font);
    text.setString(judgment);
    text.setCharacterSize(24);
    text.setFillColor(Color::White);
    text.setPosition(100, 100);

    window.draw(text);
}

int main() {
    RenderWindow window(VideoMode(1500, 800), "���� ����");

    srand(static_cast<unsigned>(time(nullptr))); // ���� ���� �õ� �ʱ�ȭ

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        // ��Ʈ �ð��� �Է� �ð� �ùķ��̼� (������)
        int noteTime = rand() % 1000; // 0���� 999 �и��� ������ ������ ��Ʈ �ð�
        int inputTime = rand() % 1000; // 0���� 999 �и��� ������ ������ �Է� �ð�

        string judgment = CalculateNoteJudgment(noteTime, inputTime);

        window.clear();
        DisplayJudgment(window, judgment);
        window.display();
    }

    return 0;
}
