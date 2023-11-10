#include "game_functions.h"
#include "MusicSelection.h"

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
            return;
        }
    }

    // 게임 시작 화면 렌더링 및 이벤트 처리
    void run() {
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();
                else if (event.type == Event::MouseButtonPressed) {
                    // 화면 클릭 이벤트 감지]
                    MusicSelection musicSelection;
                    musicSelection.run();

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
