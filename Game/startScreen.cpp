#include "StartScreen.h"
#include "game_functions.h"
#include "MusicSelection.h"

StartScreen::StartScreen() : window(sf::VideoMode(1500, 843), "Melody BeatDown Start~!") {
    // 게임 시작 화면의 배경 이미지 로드
    if (!backgroundTexture.loadFromFile("images/start_background.png")) {
        // 이미지 로드에 실패한 경우, 그냥 리턴하고 아무것도 하지 않음
        return;
    }
}

void StartScreen::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // 창 닫기 이벤트 감지 시 창을 닫음
            else if (event.type == sf::Event::MouseButtonPressed) {
                // 화면 클릭 이벤트 감지 시, 음악 선택 화면으로 전환
                MusicSelection musicSelection;
                musicSelection.run();

                window.close(); // 게임 시작 화면은 더 이상 필요하지 않으므로 창을 닫음
            }
        }

        window.clear();                      // 창 내용을 지우고
        DisplayBackground(window, backgroundTexture);  // 배경 이미지를 창에 렌더링
        window.display();                    // 창을 화면에 표시
    }
}
