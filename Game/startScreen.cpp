#include "StartScreen.h"
#include "game_functions.h"
#include "MusicSelection.h"

StartScreen::StartScreen() : window(sf::VideoMode(1500, 843), "Melody BeatDown Start~!") {
    // ���� ���� ȭ���� ��� �̹��� �ε�
    if (!backgroundTexture.loadFromFile("images/start_background.png")) {
        // �̹��� �ε忡 ������ ���, �׳� �����ϰ� �ƹ��͵� ���� ����
        return;
    }
}

void StartScreen::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // â �ݱ� �̺�Ʈ ���� �� â�� ����
            else if (event.type == sf::Event::MouseButtonPressed) {
                // ȭ�� Ŭ�� �̺�Ʈ ���� ��, ���� ���� ȭ������ ��ȯ
                MusicSelection musicSelection;
                musicSelection.run();

                window.close(); // ���� ���� ȭ���� �� �̻� �ʿ����� �����Ƿ� â�� ����
            }
        }

        window.clear();                      // â ������ �����
        DisplayBackground(window, backgroundTexture);  // ��� �̹����� â�� ������
        window.display();                    // â�� ȭ�鿡 ǥ��
    }
}
