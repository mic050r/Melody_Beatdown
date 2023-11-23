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
        // ��������Ʈ�� ũ�⸦ �̹����� ���� ũ��� ����
        sprite.setScale(sf::Vector2f(50.f / texture.getSize().x, 30.f / texture.getSize().y));
        // �ʱ� ��ġ ����
        sprite.setPosition(initialX, initialY);
    }

    void move() {
        sprite.move(0, speed);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(1500, 843), "Rhythm Game");
    window.setFramerateLimit(60);

    // ���� �߻��� ���� �õ� ����
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    sf::Music music;
    if (!music.openFromFile("music/Aespa-Better-Things.wav")) {
        std::cerr << "Failed to load music" << std::endl;
        return -1;
    }
    music.play();

    sf::Clock clock;
    sf::Time elapsed;
    sf::Time noteSpawnTime; // ��Ʈ ���� �ֱ�

    std::vector<Note*> notes;  // Note �����͸� ����Ͽ� ���� �Ҵ�
    float noteSpeed = 5.0f;

    // �ϴ� �޴��� ����
    std::vector<sf::Text> menu;
    sf::Font font;
    if (!font.loadFromFile("font/NanumGothic-Bold.ttf")) {  // ��Ʈ ������ �ִ� ��η� ����
        std::cerr << "Failed to load font" << std::endl;
        return -1;
    }

    // �޴��� �ؽ�Ʈ �߰�
    menu.push_back(sf::Text("D", font, 50));
    menu.push_back(sf::Text("F", font, 50));
    menu.push_back(sf::Text("J", font, 50));
    menu.push_back(sf::Text("K", font, 50));

    // �޴��� ��ġ ����
    float menuX = window.getSize().x / 2.0f - (menu.size() * 70.0f) / 2.0f;
    float menuY = window.getSize().y - 70.0f;

    for (auto& menuItem : menu) {
        menuItem.setPosition(menuX, menuY);
        menuX += 70.0f;
    }

    int combo = 0;  // ��ü �޺� ��

    // ���뼱 ����
    sf::RectangleShape separatorLine(sf::Vector2f(window.getSize().x, 2));
    separatorLine.setFillColor(sf::Color::Red);
    separatorLine.setPosition(0, window.getSize().y - 80);

    // ���� ���� ����
    float judgmentRange = 50.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Ű �̺�Ʈ ó��
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::D) {
                    // D Ű�� ������ �� ó��
                    if (!notes.empty() && notes.back()->sprite.getPosition().x == menu[0].getPosition().x) {
                        float noteY = notes.back()->sprite.getPosition().y;
                        if (noteY > menuY && noteY < menuY + judgmentRange) {
                            delete notes.back();  // ���� ��Ʈ ���� �� �޸� ����
                            notes.pop_back();
                            combo++;
                            std::cout << "Combo: " << combo << std::endl;
                        }
                    }
                }
                else if (event.key.code == sf::Keyboard::F) {
                    // F Ű�� ������ �� ó��
                    if (!notes.empty() && notes.back()->sprite.getPosition().x == menu[1].getPosition().x) {
                        float noteY = notes.back()->sprite.getPosition().y;
                        if (noteY > menuY && noteY < menuY + judgmentRange) {
                            delete notes.back();  // ���� ��Ʈ ���� �� �޸� ����
                            notes.pop_back();
                            combo++;
                            std::cout << "Combo: " << combo << std::endl;
                        }
                    }
                }
                else if (event.key.code == sf::Keyboard::J) {
                    // J Ű�� ������ �� ó��
                    if (!notes.empty() && notes.back()->sprite.getPosition().x == menu[2].getPosition().x) {
                        float noteY = notes.back()->sprite.getPosition().y;
                        if (noteY > menuY && noteY < menuY + judgmentRange) {
                            delete notes.back();  // ���� ��Ʈ ���� �� �޸� ����
                            notes.pop_back();
                            combo++;
                            std::cout << "Combo: " << combo << std::endl;
                        }
                    }
                }
                else if (event.key.code == sf::Keyboard::K) {
                    // K Ű�� ������ �� ó��
                    if (!notes.empty() && notes.back()->sprite.getPosition().x == menu[3].getPosition().x) {
                        float noteY = notes.back()->sprite.getPosition().y;
                        if (noteY > menuY && noteY < menuY + judgmentRange) {
                            delete notes.back();  // ���� ��Ʈ ���� �� �޸� ����
                            notes.pop_back();
                            combo++;
                            std::cout << "Combo: " << combo << std::endl;
                        }
                    }
                }
            }
        }

        elapsed = clock.restart();

        // ��Ʈ ���� �ֱ⸦ �������� ����
        if (noteSpawnTime <= sf::Time::Zero) {
            noteSpawnTime = sf::seconds(static_cast<float>(std::rand() % 4 + 1)); // 1�ʺ��� 4�� ������ ���� ��
            // �������� ��Ʈ�� �ʱ� ��ġ�� �����Ͽ� ����
            float randomX = menu[std::rand() % menu.size()].getPosition().x;
            notes.push_back(new Note(noteSpeed, "images/noteBasic.png", randomX, 0));
        }
        else {
            noteSpawnTime -= elapsed;
        }

        // Note �̵�
        for (auto& note : notes) {
            note->move();
        }

        // ȭ���� ��� Note ���� �� �޸� ����
        notes.erase(std::remove_if(notes.begin(), notes.end(), [&](Note* note) {
            bool outOfBounds = note->sprite.getPosition().y > window.getSize().y;
            if (outOfBounds) {
                delete note;  // �޸� ����
            }
            return outOfBounds;
            }), notes.end());

        // ȭ�� ������Ʈ
        window.clear();

        // Note �׸���
        for (const auto& note : notes) {
            window.draw(note->sprite);
        }

        // �޴��� �׸���
        for (const auto& menuItem : menu) {
            window.draw(menuItem);
        }

        // ���뼱 �׸���
        window.draw(separatorLine);

        window.display();
    }

    // ���α׷� ���� ���� ��� ��Ʈ �޸� ����
    for (auto& note : notes) {
        delete note;
    }

    return 0;
}
