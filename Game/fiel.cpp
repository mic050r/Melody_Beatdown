#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <bzlib.h>

using namespace sf;
using namespace std;

// 판정 임계값 상수 정의
const int GREAT_THRESHOLD = 50; // 최고 판정 임계값
const int GOOD_THRESHOLD = 100; // 좋음 판정 임계값

// 노트 판정을 계산하는 함수
string CalculateNoteJudgment(int noteTime, int inputTime) {
    int timeDifference = abs(noteTime - inputTime);

    if (timeDifference < GREAT_THRESHOLD) {
        return "최고"; // 최고 판정
    }
    else if (timeDifference < GOOD_THRESHOLD) {
        return "좋음"; // 좋음 판정
    }
    else {
        return "나쁨"; // 나쁨 판정
    }
}

// SFML을 사용하여 화면에 판정을 표시하는 함수
void DisplayJudgment(RenderWindow& window, const string& judgment) {
    /*Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cerr << "폰트를 찾을 수 없습니다!" << endl;
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
    RenderWindow window(VideoMode(1500, 800), "리듬 게임");

    srand(static_cast<unsigned>(time(nullptr))); // 난수 생성 시드 초기화

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        // 노트 시간과 입력 시간 시뮬레이션 (예제용)
        int noteTime = rand() % 1000; // 0부터 999 밀리초 범위의 임의의 노트 시간
        int inputTime = rand() % 1000; // 0부터 999 밀리초 범위의 임의의 입력 시간

        string judgment = CalculateNoteJudgment(noteTime, inputTime);

        window.clear();
        DisplayJudgment(window, judgment);
        window.display();
    }

    return 0;
}
