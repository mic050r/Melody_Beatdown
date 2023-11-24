#ifndef MUSICSELECTION_H
#define MUSICSELECTION_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <memory>

class MusicSelection {
public:
    MusicSelection();
    // ���� ���� �� ���� ����
    void run();

private:
    struct MusicInfo {
        sf::Texture texture; 
        std::string path;
        std::shared_ptr<sf::Music> music;

        MusicInfo(const std::string& path, const sf::Texture& texture, const std::shared_ptr<sf::Music>& music)
            : path(path), texture(texture), music(music) {}
    };

    int currentMusicIndex;
    bool startGame;

    sf::RectangleShape nextButton;
    sf::RectangleShape prevButton;  // prevButton ����
    sf::Texture nextButtonTexture;
    sf::Texture prevButtonTexture;

    std::vector<MusicInfo> musicInfoList;
    std::vector<sf::Texture> musicTextures;
    
};

#endif // MUSICSELECTION_H
