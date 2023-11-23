#include "game_functions.h"
#include "MusicSelection.h"

using namespace sf;

// StartScreen Ŭ����: ���� ���� ȭ��� ���õ� ����� ����ϴ� Ŭ����
class StartScreen {
private:
    RenderWindow window;            // ���� â ��ü
    Texture backgroundTexture;      // ���� ���� ȭ�� ��� �̹��� �ؽ�ó

public:
    // ������: ���� â ũ�� ���� �� ��� �̹��� �ε�
    StartScreen() : window(VideoMode(1500, 843), "Melody BeatDown Start~!") {
       
        // ���� ���� ȭ���� ��� �̹��� �ε�
        if (!backgroundTexture.loadFromFile("images/start_background.png")) {
            // �̹��� �ε忡 ������ ���, �׳� �����ϰ� �ƹ��͵� ���� ����
            return;
        }
    }

    // ���� ���� ȭ�� ������ �� �̺�Ʈ ó��
    void run() {
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close(); // â �ݱ� �̺�Ʈ ���� �� â�� ����
                else if (event.type == Event::MouseButtonPressed) {
                    // ȭ�� Ŭ�� �̺�Ʈ ���� ��, ���� ���� ȭ������ ��ȯ
                    MusicSelection musicSelection;
                    musicSelection.run();

                    window.close(); // ���� ���� ȭ���� �� �̻� �ʿ����� �����Ƿ� â�� ����
                }
            }

            window.clear();                     // â ������ �����
            DisplayBackground(window, backgroundTexture);  // ��� �̹����� â�� ������
            window.display();                   // â�� ȭ�鿡 ǥ��
        }
    }
};

// ���� �Լ�: ���� ���� ȭ�� ��ü�� �����Ͽ� ������ ������
int main() {
    StartScreen startScreen;    // StartScreen ��ü�� �����Ͽ� ���� ���� ȭ�� ���� ����
    startScreen.run();          // ���� ���� ȭ�� ����
   

    return 0;
}
