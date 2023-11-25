#include "RhythmGame.h"
#include "Note.h"
#include "game_functions.h"
#include "ResultScreen.h"
#include "constants.h"
#include <SFML/Audio.hpp>
#include "constants.h"

// RhythmGame Ŭ������ �������Դϴ�. ���� ���õ� � ���� â ũ��, ���� ���� ��� ���� �ʱ�ȭ
RhythmGame::RhythmGame(int nowSelected)
    : window(sf::VideoMode(kWindowWidth, kWindowHeight), "Rhythm Game"), gameDuration(sf::seconds(50)), noteSpeed(7.0f), judgmentRange(70.0f), PERFECT(0), GOOD(0), MISS(0) {
    window.setFramerateLimit(60);

    // ���� ���õ� � ���� ��� �̹��� ��θ� ����
     backgroundImagePath = kBackgroundPathPrefix + std::to_string(nowSelected + 1) + ".png";

    // �� ���ÿ� ���� ���� �ʱ�ȭ
    switch (nowSelected) {
    case 0:
        titleName = "Spicy";
        song = "music/Aespa-Spicy.wav";
        break;
    case 1:
        titleName = "Hold On Tight";
        song = "music/Aespa-Hold-On-Tight.wav";
        break;
    case 2:
        titleName = "Better Things";
        song = "music/Aespa-Better-Things.wav";
    }

    // ���� ���� ȭ���� ��� �̹��� �ε�
    if (!backgroundTexture.loadFromFile(backgroundImagePath)) {
        std::cerr << "�̹��� �ε� ����" << std::endl;
        return;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // ��Ʈ �ε�
    if (!font.loadFromFile("font/NanumGothic-Bold.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }

   

    // �޴��� ���� �̹��� �ε�
    for (int i = 0; i < 4; ++i) {
        sf::RectangleShape menuItem(sf::Vector2f(148.0f, 70.0f));  // ������ ���簢�� ũ�� ���� ����
        menuItem.setFillColor(sf::Color::White);
        menuImages.push_back(menuItem);
    }
    // �޴� �̹��� ��ġ ����
    float menuX = window.getSize().x / 2.0f - (menuImages.size() * 140.0f) / 2.0f;
    float menuY = window.getSize().y - 70.0f;

    for (auto& menuImage : menuImages) {
        menuImage.setPosition(menuX, menuY);
        menuX += 150.0f; // ���⿡�� ������ ����
    }


    // ��ܿ� ǥ�õǴ� �и��� ����
    separatorLine.setSize(sf::Vector2f(window.getSize().x, 2)); // ���� ���� : ���� �������� ���� ���̿� �����ϰ� ����
    separatorLine.setFillColor(sf::Color::Red);
    separatorLine.setPosition(0, window.getSize().y - 80);

    // ���� �÷��� ȭ�� ��ܿ� ǥ�õǴ� ���� �޺� �� ����
    comboText.setFont(font);
    comboText.setCharacterSize(50);
    comboText.setPosition(1175, 10);
    comboText.setString("Combo: 0");
}

// ��ǥ �Է� ó�� �Լ�
void RhythmGame::handleNoteInput(float judgmentRange) {
    if (!notes.empty()) {
        float noteY = notes.back()->sprite.getPosition().y;
        // �Է¿� ���� ���� ó��
        if (noteY > window.getSize().y - 80 && noteY < window.getSize().y - 80 + judgmentRange) {
            delete notes.back();
            notes.pop_back();
            combo++;
            // Perfect ���� �� ī��Ʈ
            judgment = "Perfect";
            PERFECT++;
            std::cout << "Combo: " << combo << " - Perfect" << std::endl;
        }
        else if (noteY > window.getSize().y - 100 && noteY < window.getSize().y - 100 + 2 * judgmentRange) {
            delete notes.back();
            notes.pop_back();
            combo++;
            // Good ���� �� ī��Ʈ
            judgment = "Good";
            GOOD++;
            std::cout << "Combo: " << combo << " - Good" << std::endl;
        }
        else {
            // Miss ���� �� ī��Ʈ
            judgment = "Miss";
            MISS++;
            std::cout << "Miss" << std::endl;
        }
    }
}

// ��ǥ �׸��� �Լ�
void RhythmGame::drawNotes() {
    for (const auto& note : notes) {
        window.draw(note->sprite);
    }
}

// �޴� �ؽ�Ʈ �׸��� �Լ�
void RhythmGame::drawMenu() {
    // �޴� �̹��� �׸���
    for (const auto& menuImage : menuImages) {
        window.draw(menuImage);
    }
    drawTexts();
    drawNotes();
}

// �ؽ�Ʈ �׸��� �Լ�
void RhythmGame::drawTexts() {
    DisplayText(window, "D", font, 50, sf::Color::Black, 530, 776);
    DisplayText(window, "F", font, 50, sf::Color::Black, 680, 776);
    DisplayText(window, "J", font, 50, sf::Color::Black, 830, 776);
    DisplayText(window, "K", font, 50, sf::Color::Black, 977, 776);

    // ���� �÷��� ȭ�� ��ܿ� ǥ�õǴ� �� ���� ����
    DisplayText(window, titleName, font, 50, sf::Color::White, 15, 771);
    comboText.setString("Combo: " + std::to_string(combo));
    window.draw(comboText);

    sf::Text judgmentText(judgment, font, 50);
    judgmentText.setPosition(659, 541);
    window.draw(judgmentText);
}

// ��ư �׸��� �� Ŭ�� �̺�Ʈ ó�� �Լ�
void RhythmGame::displayButtons() {
    prevButton.setSize(sf::Vector2f(80, 80));
    prevButton.setPosition(100, 100);
    std::string prevButtonPath = "images/music_prev_btn.png";
    sf::Texture prevButtonTexture;
    DisplayButton(window, prevButton, prevButtonPath, prevButtonTexture, 25, 23, 80, 80);

    // ���콺 ���� ��ư�� Ŭ���Ǿ��� ���� ó��
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if (prevButton.getGlobalBounds().contains(mousePos)) {
            std::cout << "Ŭ��" << std::endl;
            music.stop();
            HandleMouseClick(prevButton, mousePos);
        }
    }
}

// ���� ���� �Լ�
void RhythmGame::run() {
    // ���� �ε� �� ���
    if (!music.openFromFile(song)) {
        std::cerr << "Failed to load music" << std::endl;
        return;
    }
    music.play();

    // ���� ����
    while (window.isOpen() && gameClock.getElapsedTime() < gameDuration) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                // Ű �Է¿� ���� ��ǥ �Է� ó��
                handleNoteInput(judgmentRange);
            }
        }

        elapsed = clock.restart();

        // ��ǥ ���� Ÿ�̹� ó�� - �ð� ���� ����
        if (noteSpawnTime <= sf::Time::Zero) {
            noteSpawnTime = sf::seconds(static_cast<float>(std::rand() % 2 + 1)); // ��: 1���� 2�� ���� ����
            float randomX = menuImages[std::rand() % menuImages.size()].getPosition().x;

            notes.push_back(new Note(noteSpeed, "images/noteBasic.png", randomX, 0));
        }
        else {
            noteSpawnTime -= elapsed;
        }

        // ��ǥ �̵� �� ȭ�� ��� ��ǥ ����
        for (auto& note : notes) {
            note->move();
        }

        notes.erase(std::remove_if(notes.begin(), notes.end(), [&](Note* note) {
            bool outOfBounds = note->sprite.getPosition().y > window.getSize().y;
            if (outOfBounds) {
                delete note;
            }
            return outOfBounds;
            }), notes.end());

        window.clear();

        // ���� �÷��� ȭ�� �׸���
        DisplayBackground(window, backgroundTexture);
        drawMenu();
        window.draw(separatorLine);
        
        displayButtons();
        window.display();
    }

    // �����ִ� ��ǥ�� ����
    for (auto& note : notes) {
        delete note;
    }

    // ���� ��� ȭ�� ǥ��
    music.stop();
    ResultScreen resultScreen(combo, PERFECT, GOOD, MISS, nowSelected);
    std::cout << nowSelected;
    resultScreen.run();
}
