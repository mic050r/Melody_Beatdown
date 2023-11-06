#ifndef MUSICSELECTION_H
#define MUSICSELECTION_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <memory>

class MusicSelection {
public:
    MusicSelection();

    // 음악 선택 및 관리 로직
    void run();

private:
    struct MusicInfo {
        std::string path;
        sf::Texture texture;
        std::shared_ptr<sf::Music> music;

        MusicInfo(const std::string& path, const sf::Texture& texture, const std::shared_ptr<sf::Music>& music)
            : path(path), texture(texture), music(music) {}
    };

    std::vector<MusicInfo> musicInfoList;
    std::vector<sf::Texture> musicTextures;
    int currentMusicIndex;

    sf::RectangleShape nextButton;
    sf::RectangleShape prevButton;
    bool startGame;
};

#endif // MUSICSELECTION_H
