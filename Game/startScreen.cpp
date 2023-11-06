
#include "MusicSelection.h"
#include "game_functions.h"


using namespace sf;

// StartScreen 클래스: 게임 시작 화면과 관련된 기능을 담당하는 클래스
class StartScreen {
private:
    RenderWindow window;
    Texture backgroundTexture;

public:
    StartScreen() : window(VideoMode(1500, 843), "리듬 게임") {
        // 게임 시작 화면의 배경 이미지 로드
        if (!backgroundTexture.loadFromFile("images/start_background.png")) {
            // 이미지 로드 실패 시 예외 처리 또는 오류 처리를 추가할 수 있음
            return;
        }
    }

    void run() {
        MusicSelection musicSelection;  // MusicSelection 객체 생성

        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();
                else if (event.type == Event::MouseButtonPressed) {
                    // 화면 클릭 이벤트 감지
                    musicSelection.run();  // MusicSelection 실행
                    window.close();
                }
            }

            window.clear();

            DisplayBackground(window, backgroundTexture);

            window.display();
        }
    }
};

int main() {
    // StartScreen 객체를 생성하여 게임 시작 화면 관리 수행
    StartScreen startScreen;
    startScreen.run();

    return 0;
}
