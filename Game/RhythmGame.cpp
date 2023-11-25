#include "RhythmGame.h"
#include "Note.h"
#include "game_functions.h"
#include "ResultScreen.h"
#include "constants.h"
#include <SFML/Audio.hpp>
#include "constants.h"

// RhythmGame 클래스의 생성자입니다. 현재 선택된 곡에 따라 창 크기, 음악 파일 경로 등을 초기화
RhythmGame::RhythmGame(int nowSelected)
    : window(sf::VideoMode(kWindowWidth, kWindowHeight), "Rhythm Game"), gameDuration(sf::seconds(50)), noteSpeed(7.0f), judgmentRange(70.0f), PERFECT(0), GOOD(0), MISS(0) {
    window.setFramerateLimit(60);

    // 현재 선택된 곡에 따라 배경 이미지 경로를 설정
     backgroundImagePath = kBackgroundPathPrefix + std::to_string(nowSelected + 1) + ".png";

    // 곡 선택에 따른 정보 초기화
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

    // 게임 시작 화면의 배경 이미지 로드
    if (!backgroundTexture.loadFromFile(backgroundImagePath)) {
        std::cerr << "이미지 로드 실패" << std::endl;
        return;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // 폰트 로드
    if (!font.loadFromFile("font/NanumGothic-Bold.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }

   

    // 메뉴에 대한 이미지 로드
    for (int i = 0; i < 4; ++i) {
        sf::RectangleShape menuItem(sf::Vector2f(148.0f, 70.0f));  // 검정색 직사각형 크기 조절 가능
        menuItem.setFillColor(sf::Color::White);
        menuImages.push_back(menuItem);
    }
    // 메뉴 이미지 위치 설정
    float menuX = window.getSize().x / 2.0f - (menuImages.size() * 140.0f) / 2.0f;
    float menuY = window.getSize().y - 70.0f;

    for (auto& menuImage : menuImages) {
        menuImage.setPosition(menuX, menuY);
        menuX += 150.0f; // 여기에서 간격을 조절
    }


    // 상단에 표시되는 분리선 설정
    separatorLine.setSize(sf::Vector2f(window.getSize().x, 2)); // 가로 길이 : 현재 윈도우의 가로 길이와 동일하게 설정
    separatorLine.setFillColor(sf::Color::Red);
    separatorLine.setPosition(0, window.getSize().y - 80);

    // 게임 플레이 화면 상단에 표시되는 현재 콤보 수 설정
    comboText.setFont(font);
    comboText.setCharacterSize(50);
    comboText.setPosition(1175, 10);
    comboText.setString("Combo: 0");
}

// 음표 입력 처리 함수
void RhythmGame::handleNoteInput(float judgmentRange) {
    if (!notes.empty()) {
        float noteY = notes.back()->sprite.getPosition().y;
        // 입력에 대한 판정 처리
        if (noteY > window.getSize().y - 80 && noteY < window.getSize().y - 80 + judgmentRange) {
            delete notes.back();
            notes.pop_back();
            combo++;
            // Perfect 판정 및 카운트
            judgment = "Perfect";
            PERFECT++;
            std::cout << "Combo: " << combo << " - Perfect" << std::endl;
        }
        else if (noteY > window.getSize().y - 100 && noteY < window.getSize().y - 100 + 2 * judgmentRange) {
            delete notes.back();
            notes.pop_back();
            combo++;
            // Good 판정 및 카운트
            judgment = "Good";
            GOOD++;
            std::cout << "Combo: " << combo << " - Good" << std::endl;
        }
        else {
            // Miss 판정 및 카운트
            judgment = "Miss";
            MISS++;
            std::cout << "Miss" << std::endl;
        }
    }
}

// 음표 그리기 함수
void RhythmGame::drawNotes() {
    for (const auto& note : notes) {
        window.draw(note->sprite);
    }
}

// 메뉴 텍스트 그리기 함수
void RhythmGame::drawMenu() {
    // 메뉴 이미지 그리기
    for (const auto& menuImage : menuImages) {
        window.draw(menuImage);
    }
    drawTexts();
    drawNotes();
}

// 텍스트 그리기 함수
void RhythmGame::drawTexts() {
    DisplayText(window, "D", font, 50, sf::Color::Black, 530, 776);
    DisplayText(window, "F", font, 50, sf::Color::Black, 680, 776);
    DisplayText(window, "J", font, 50, sf::Color::Black, 830, 776);
    DisplayText(window, "K", font, 50, sf::Color::Black, 977, 776);

    // 게임 플레이 화면 상단에 표시되는 곡 제목 설정
    DisplayText(window, titleName, font, 50, sf::Color::White, 15, 771);
    comboText.setString("Combo: " + std::to_string(combo));
    window.draw(comboText);

    sf::Text judgmentText(judgment, font, 50);
    judgmentText.setPosition(659, 541);
    window.draw(judgmentText);
}

// 버튼 그리기 및 클릭 이벤트 처리 함수
void RhythmGame::displayButtons() {
    prevButton.setSize(sf::Vector2f(80, 80));
    prevButton.setPosition(100, 100);
    std::string prevButtonPath = "images/music_prev_btn.png";
    sf::Texture prevButtonTexture;
    DisplayButton(window, prevButton, prevButtonPath, prevButtonTexture, 25, 23, 80, 80);

    // 마우스 왼쪽 버튼이 클릭되었을 때의 처리
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if (prevButton.getGlobalBounds().contains(mousePos)) {
            std::cout << "클릭" << std::endl;
            music.stop();
            HandleMouseClick(prevButton, mousePos);
        }
    }
}

// 게임 루프 함수
void RhythmGame::run() {
    // 음악 로드 및 재생
    if (!music.openFromFile(song)) {
        std::cerr << "Failed to load music" << std::endl;
        return;
    }
    music.play();

    // 게임 루프
    while (window.isOpen() && gameClock.getElapsedTime() < gameDuration) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                // 키 입력에 대한 음표 입력 처리
                handleNoteInput(judgmentRange);
            }
        }

        elapsed = clock.restart();

        // 음표 생성 타이밍 처리 - 시간 간격 조절
        if (noteSpawnTime <= sf::Time::Zero) {
            noteSpawnTime = sf::seconds(static_cast<float>(std::rand() % 2 + 1)); // 예: 1에서 2초 사이 간격
            float randomX = menuImages[std::rand() % menuImages.size()].getPosition().x;

            notes.push_back(new Note(noteSpeed, "images/noteBasic.png", randomX, 0));
        }
        else {
            noteSpawnTime -= elapsed;
        }

        // 음표 이동 및 화면 벗어난 음표 제거
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

        // 게임 플레이 화면 그리기
        DisplayBackground(window, backgroundTexture);
        drawMenu();
        window.draw(separatorLine);
        
        displayButtons();
        window.display();
    }

    // 남아있는 음표들 삭제
    for (auto& note : notes) {
        delete note;
    }

    // 최종 결과 화면 표시
    music.stop();
    ResultScreen resultScreen(combo, PERFECT, GOOD, MISS, nowSelected);
    std::cout << nowSelected;
    resultScreen.run();
}
