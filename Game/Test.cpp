#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Note {
public:
    sf::Sprite sprite;
    sf::Texture texture;
    float speed;

    Note(float speed, const std::string& imagePath, float initialX, float initialY)
        : speed(speed) {
        if (!texture.loadFromFile(imagePath)) {
            std::cerr << "Failed to load texture" << std::endl;
        }
        sprite.setTexture(texture);
        sprite.setScale(sf::Vector2f(50.f / texture.getSize().x, 30.f / texture.getSize().y));
        sprite.setPosition(initialX, initialY);
    }

    void move() {
        sprite.move(0, speed);
    }
};

void handleNoteInput(std::vector<Note*>& notes, int& combo, sf::RenderWindow& window, float judgmentRange, std::string& judgment);

void handleNoteInput(std::vector<Note*>& notes, int& combo, sf::RenderWindow& window, float judgmentRange, std::string& judgment) {
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

int main() {
    sf::RenderWindow window(sf::VideoMode(1500, 843), "Rhythm Game");
    window.setFramerateLimit(60);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    sf::Music music;
    if (!music.openFromFile("music/Aespa-Better-Things.wav")) {
        std::cerr << "Failed to load music" << std::endl;
        return -1;
    }
    music.play();

    sf::Clock clock;
    sf::Time elapsed;
    sf::Time noteSpawnTime;

    sf::Clock gameClock;
    const sf::Time gameDuration = sf::seconds(60);

    std::vector<Note*> notes;
    float noteSpeed = 5.0f;

    std::vector<sf::Text> menu;
    sf::Font font;
    if (!font.loadFromFile("font/NanumGothic-Bold.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return -1;
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

    int combo = 0;
    float judgmentRange = 50.0f;
    std::string judgment = ""; // "Great", "Good", "Miss"

    sf::RectangleShape separatorLine(sf::Vector2f(window.getSize().x, 2));
    separatorLine.setFillColor(sf::Color::Red);
    separatorLine.setPosition(0, window.getSize().y - 80);

    // 추가된 부분: 노래 제목 표시 텍스트
    sf::Text songTitleText("Aespa - Better Things", font, 30);
    songTitleText.setPosition(10, 10);

    // 추가된 부분: 콤보 표시 텍스트
    sf::Text comboText("Combo: 0", font, 30);
    comboText.setPosition(window.getSize().x - 150, 10);

    while (window.isOpen() && gameClock.getElapsedTime() < gameDuration) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                handleNoteInput(notes, combo, window, judgmentRange, judgment);
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

        for (const auto& note : notes) {
            window.draw(note->sprite);
        }

        for (const auto& menuItem : menu) {
            window.draw(menuItem);
        }

        window.draw(separatorLine);

        // 추가된 부분: 텍스트 그리기
        window.draw(songTitleText);

        comboText.setString("Combo: " + std::to_string(combo));
        window.draw(comboText);

        // 추가된 부분: 판정 텍스트 그리기
        sf::Text judgmentText(judgment, font, 50);
        judgmentText.setPosition(window.getSize().x / 2.0f - judgmentText.getLocalBounds().width / 2.0f, window.getSize().y - 150);
        window.draw(judgmentText);

        window.display();
    }

    for (auto& note : notes) {
        delete note;
    }

    std::cout << "Final Combo: " << combo << std::endl;

    return 0;
}
