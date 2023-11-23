#include "game_functions.h"
#include "MusicSelection.h"

using namespace sf;

// StartScreen 클래스: 게임 시작 화면과 관련된 기능을 담당하는 클래스
class StartScreen {
private:
    RenderWindow window;            // 게임 창 객체
    Texture backgroundTexture;      // 게임 시작 화면 배경 이미지 텍스처

public:
    // 생성자: 게임 창 크기 설정 및 배경 이미지 로드
    StartScreen() : window(VideoMode(1500, 843), "Melody BeatDown Start~!") {
       
        // 게임 시작 화면의 배경 이미지 로드
        if (!backgroundTexture.loadFromFile("images/start_background.png")) {
            // 이미지 로드에 실패한 경우, 그냥 리턴하고 아무것도 하지 않음
            return;
        }
    }

    // 게임 시작 화면 렌더링 및 이벤트 처리
    void run() {
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close(); // 창 닫기 이벤트 감지 시 창을 닫음
                else if (event.type == Event::MouseButtonPressed) {
                    // 화면 클릭 이벤트 감지 시, 음악 선택 화면으로 전환
                    MusicSelection musicSelection;
                    musicSelection.run();

                    window.close(); // 게임 시작 화면은 더 이상 필요하지 않으므로 창을 닫음
                }
            }

            window.clear();                     // 창 내용을 지우고
            DisplayBackground(window, backgroundTexture);  // 배경 이미지를 창에 렌더링
            window.display();                   // 창을 화면에 표시
        }
    }
};

// 메인 함수: 게임 시작 화면 객체를 생성하여 게임을 시작함
int main() {
    StartScreen startScreen;    // StartScreen 객체를 생성하여 게임 시작 화면 관리 수행
    startScreen.run();          // 게임 시작 화면 실행
   

    return 0;
}
