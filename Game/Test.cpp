#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>  // std::rand, std::srand
#include <ctime>    // std::time

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
        // 스프라이트의 크기를 이미지의 원본 크기로 설정
        sprite.setScale(sf::Vector2f(50.f / texture.getSize().x, 30.f / texture.getSize().y));
        // 초기 위치 설정
        sprite.setPosition(initialX, initialY);
    }

    void move() {
        sprite.move(0, speed);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(1500, 843), "Rhythm Game");
    window.setFramerateLimit(60);

    // 난수 발생을 위한 시드 설정
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    sf::Music music;
    if (!music.openFromFile("music/Aespa-Better-Things.wav")) {
        std::cerr << "Failed to load music" << std::endl;
        return -1;
    }
    music.play();

    sf::Clock clock;
    sf::Time elapsed;
    sf::Time noteSpawnTime; // 노트 생성 주기

    std::vector<Note*> notes;  // Note 포인터를 사용하여 동적 할당
    float noteSpeed = 5.0f;

    // 하단 메뉴바 생성
    std::vector<sf::Text> menu;
    sf::Font font;
    if (!font.loadFromFile("font/NanumGothic-Bold.ttf")) {  // 폰트 파일이 있는 경로로 수정
        std::cerr << "Failed to load font" << std::endl;
        return -1;
    }

    // 메뉴바 텍스트 추가
    menu.push_back(sf::Text("D", font, 50));
    menu.push_back(sf::Text("F", font, 50));
    menu.push_back(sf::Text("J", font, 50));
    menu.push_back(sf::Text("K", font, 50));

    // 메뉴바 위치 설정
    float menuX = window.getSize().x / 2.0f - (menu.size() * 70.0f) / 2.0f;
    float menuY = window.getSize().y - 70.0f;

    for (auto& menuItem : menu) {
        menuItem.setPosition(menuX, menuY);
        menuX += 70.0f;
    }

    int combo = 0;  // 전체 콤보 수

    // 절취선 생성
    sf::RectangleShape separatorLine(sf::Vector2f(window.getSize().x, 2));
    separatorLine.setFillColor(sf::Color::Red);
    separatorLine.setPosition(0, window.getSize().y - 80);

    // 판정 범위 설정
    float judgmentRange = 50.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // 키 이벤트 처리
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::D) {
                    // D 키를 눌렀을 때 처리
                    if (!notes.empty() && notes.back()->sprite.getPosition().x == menu[0].getPosition().x) {
                        float noteY = notes.back()->sprite.getPosition().y;
                        if (noteY > menuY && noteY < menuY + judgmentRange) {
                            delete notes.back();  // 맞은 노트 삭제 및 메모리 해제
                            notes.pop_back();
                            combo++;
                            std::cout << "Combo: " << combo << std::endl;
                        }
                    }
                }
                else if (event.key.code == sf::Keyboard::F) {
                    // F 키를 눌렀을 때 처리
                    if (!notes.empty() && notes.back()->sprite.getPosition().x == menu[1].getPosition().x) {
                        float noteY = notes.back()->sprite.getPosition().y;
                        if (noteY > menuY && noteY < menuY + judgmentRange) {
                            delete notes.back();  // 맞은 노트 삭제 및 메모리 해제
                            notes.pop_back();
                            combo++;
                            std::cout << "Combo: " << combo << std::endl;
                        }
                    }
                }
                else if (event.key.code == sf::Keyboard::J) {
                    // J 키를 눌렀을 때 처리
                    if (!notes.empty() && notes.back()->sprite.getPosition().x == menu[2].getPosition().x) {
                        float noteY = notes.back()->sprite.getPosition().y;
                        if (noteY > menuY && noteY < menuY + judgmentRange) {
                            delete notes.back();  // 맞은 노트 삭제 및 메모리 해제
                            notes.pop_back();
                            combo++;
                            std::cout << "Combo: " << combo << std::endl;
                        }
                    }
                }
                else if (event.key.code == sf::Keyboard::K) {
                    // K 키를 눌렀을 때 처리
                    if (!notes.empty() && notes.back()->sprite.getPosition().x == menu[3].getPosition().x) {
                        float noteY = notes.back()->sprite.getPosition().y;
                        if (noteY > menuY && noteY < menuY + judgmentRange) {
                            delete notes.back();  // 맞은 노트 삭제 및 메모리 해제
                            notes.pop_back();
                            combo++;
                            std::cout << "Combo: " << combo << std::endl;
                        }
                    }
                }
            }
        }

        elapsed = clock.restart();

        // 노트 생성 주기를 랜덤으로 설정
        if (noteSpawnTime <= sf::Time::Zero) {
            noteSpawnTime = sf::seconds(static_cast<float>(std::rand() % 4 + 1)); // 1초부터 4초 사이의 랜덤 값
            // 랜덤으로 노트의 초기 위치를 설정하여 생성
            float randomX = menu[std::rand() % menu.size()].getPosition().x;
            notes.push_back(new Note(noteSpeed, "images/noteBasic.png", randomX, 0));
        }
        else {
            noteSpawnTime -= elapsed;
        }

        // Note 이동
        for (auto& note : notes) {
            note->move();
        }

        // 화면을 벗어난 Note 삭제 및 메모리 해제
        notes.erase(std::remove_if(notes.begin(), notes.end(), [&](Note* note) {
            bool outOfBounds = note->sprite.getPosition().y > window.getSize().y;
            if (outOfBounds) {
                delete note;  // 메모리 해제
            }
            return outOfBounds;
            }), notes.end());

        // 화면 업데이트
        window.clear();

        // Note 그리기
        for (const auto& note : notes) {
            window.draw(note->sprite);
        }

        // 메뉴바 그리기
        for (const auto& menuItem : menu) {
            window.draw(menuItem);
        }

        // 절취선 그리기
        window.draw(separatorLine);

        window.display();
    }

    // 프로그램 종료 전에 모든 노트 메모리 해제
    for (auto& note : notes) {
        delete note;
    }

    return 0;
}
