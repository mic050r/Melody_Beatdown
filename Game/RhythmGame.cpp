#include "RhythmGame.h"
#include "Note.h"
#include "game_functions.h"
#include "ResultScreen.h"

RhythmGame::RhythmGame(int nowSelected)
    : window(sf::VideoMode(1500, 843), "Rhythm Game"), gameDuration(sf::seconds(5)), noteSpeed(5.0f), judgmentRange(50.0f), PERFECT(0), GOOD(0), MISS(0) {
    window.setFramerateLimit(60);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

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


    if (!font.loadFromFile("font/NanumGothic-Bold.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }

    menu.push_back(sf::Text("D", font, 50));
    menu.push_back(sf::Text("F", font, 50));
    menu.push_back(sf::Text("J", font, 50));
    menu.push_back(sf::Text("K", font, 50));

    float menuX = window.getSize().x / 2.0f - (menu.size() * 70.0f) / 2.0f;
    float menuY = window.getSize().y - 70.0f;

    for (auto& menuItem : menu) {
        menuItem.setPosition(menuX, menuY);
        menuX += 70.0f;
    }

    separatorLine.setSize(sf::Vector2f(window.getSize().x, 2));
    separatorLine.setFillColor(sf::Color::Red);
    separatorLine.setPosition(0, window.getSize().y - 80);

    songTitleText.setFont(font);
    songTitleText.setCharacterSize(30);
    songTitleText.setPosition(10, 10);
    songTitleText.setString(titleName);

    comboText.setFont(font);
    comboText.setCharacterSize(30);
    comboText.setPosition(window.getSize().x - 150, 10);
    comboText.setString("Combo: 0");
}

void RhythmGame::handleNoteInput(float judgmentRange) {
    if (!notes.empty()) {
        float noteY = notes.back()->sprite.getPosition().y;
        if (noteY > window.getSize().y - 80 && noteY < window.getSize().y - 80 + judgmentRange) {
            delete notes.back();
            notes.pop_back();
            combo++;
            
            judgment = "Perfect";
            PERFECT++;
            std::cout << "Combo: " << combo << " - Perfect" << std::endl;
        }
        else if (noteY > window.getSize().y - 80 && noteY < window.getSize().y - 80 + 2 * judgmentRange) {
            delete notes.back();
            notes.pop_back();
            combo++;
           
            judgment = "Good";
            GOOD++;
            std::cout << "Combo: " << combo << " - Good" << std::endl;
        }
        else {
            
            judgment = "Miss";
            MISS++;
            std::cout << "Miss" << std::endl;
        }
    }
}

void RhythmGame::drawNotes() {
    for (const auto& note : notes) {
        window.draw(note->sprite);
    }
}

void RhythmGame::drawMenu() {
    for (const auto& menuItem : menu) {
        window.draw(menuItem);
    }
}

void RhythmGame::drawTexts() {
    window.draw(songTitleText);

    comboText.setString("Combo: " + std::to_string(combo));
    window.draw(comboText);

    sf::Text judgmentText(judgment, font, 50);
    judgmentText.setPosition(window.getSize().x / 2.0f - judgmentText.getLocalBounds().width / 2.0f, window.getSize().y - 150);
    window.draw(judgmentText);
}


void RhythmGame::displayButtons() {
    prevButton.setSize(sf::Vector2f(80, 80));
    prevButton.setPosition(100, 100);
    std::string prevButtonPath = "images/music_prev_btn.png";
    sf::Texture prevButtonTexture;
    DisplayButton(window, prevButton, prevButtonPath, prevButtonTexture, 25, 23, 80, 80);

    // 버튼 클릭 이벤트 처리
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if (prevButton.getGlobalBounds().contains(mousePos)) {
            std::cout << "클릭" << std::endl;
            music.stop();
            HandleMouseClick(prevButton, mousePos);
        }
    }
}

void RhythmGame::run() {
    
    if (!music.openFromFile(song)) {
        std::cerr << "Failed to load music" << std::endl;
        return;
    }
    music.play();

    while (window.isOpen() && gameClock.getElapsedTime() < gameDuration) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                handleNoteInput(judgmentRange);
            }
        }

        elapsed = clock.restart();

        if (noteSpawnTime <= sf::Time::Zero) {
            noteSpawnTime = sf::seconds(static_cast<float>(std::rand() % 4 + 1));
            float randomX = menu[std::rand() % menu.size()].getPosition().x;
            notes.push_back(new Note(noteSpeed, "images/noteBasic.png", randomX, 0));
        }
        else {
            noteSpawnTime -= elapsed;
        }

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

        drawNotes();
        drawMenu();
        window.draw(separatorLine);
        drawTexts();
        displayButtons();
        window.display();
    }

    for (auto& note : notes) {
        delete note;
    }

    std::cout << "Final Combo: " << combo << std::endl;
    std::cout << "Final Combo: " << PERFECT << std::endl;
    std::cout << "Final Combo: " << GOOD << std::endl;
    std::cout << "Final Combo: " << MISS << std::endl;

    music.stop();

    ResultScreen resultScreen(combo, PERFECT, GOOD, MISS);
    resultScreen.run();
  
}
