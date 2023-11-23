#include "RhythmGame.h"
#include "Note.h"

RhythmGame::RhythmGame()
    : window(sf::VideoMode(1500, 843), "Rhythm Game"), gameDuration(sf::seconds(60)), noteSpeed(5.0f), judgmentRange(50.0f) {
    window.setFramerateLimit(60);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

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
    songTitleText.setString("Aespa - Better Things");

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
            judgment = "Great";
            std::cout << "Combo: " << combo << " - Great" << std::endl;
        }
        else if (noteY > window.getSize().y - 80 && noteY < window.getSize().y - 80 + 2 * judgmentRange) {
            delete notes.back();
            notes.pop_back();
            combo++;
            judgment = "Good";
            std::cout << "Combo: " << combo << " - Good" << std::endl;
        }
        else {
            judgment = "Miss";
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

void RhythmGame::run() {
    if (!music.openFromFile("music/Aespa-Better-Things.wav")) {
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

        window.display();
    }

    for (auto& note : notes) {
        delete note;
    }

    std::cout << "Final Combo: " << combo << std::endl;
}
