
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

// 콤보 카운터와 현재 콤보 상태를 나타내는 변수
int combo = 0;

// 정확한 입력을 받았을 때 콤보 증가하는 함수
void IncreaseCombo() {
    combo++;
}

// 화면에 현재 콤보 상태를 표시하는 함수 (SFML을 사용)
void DisplayCombo(sf::RenderWindow& window) {
    // 텍스트로 콤보 표시를 위한 Text 객체 생성
    sf::Text text;

    // 콤보 정보 문자열 생성 및 설정
    std::string comboText = "콤보: " + std::to_string(combo);
    text.setString(comboText);

    // 텍스트 위치 설정
    text.setPosition(300, 100);

    // 화면에 콤보 표시
    window.draw(text);
}
