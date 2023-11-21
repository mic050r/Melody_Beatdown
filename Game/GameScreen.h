// GameScreen.h
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "constants.h"
#include "Note.h"

using std::string;

class GameScreen {
public:
    GameScreen(sf::RenderWindow& window, int nowSelected);

    string titleName;

    const sf::RectangleShape& getPrevButton() const {
        musicInfoList[nowSelected].music->stop();
        return prevButton;
    }

    struct MusicInfo {
        std::string path;
        sf::Texture texture;
        std::shared_ptr<sf::Music> music;

        MusicInfo(const std::string& path, const sf::Texture& texture, const std::shared_ptr<sf::Music>& music)
            : path(path), texture(texture), music(music) {}
    };

    std::vector<MusicInfo> musicInfoList;
    std::vector<sf::Texture> musicTextures;
    std::vector<Note> notes;  // ���� ��Ʈ�� ������ ����

   
    void update();
    void render();
    void handleKeyPress(sf::Keyboard::Key key);  // �Լ� ���� ����� ����
    

private:
    int nowSelected; // nowSelected�� ��� ������ �߰�
    bool isSPressed;

    sf::RenderWindow& window;
    sf::RectangleShape prevButton;
    sf::Font font;

    sf::Texture backgroundTexture;
    sf::Texture gameInfoTexture;
    sf::Texture judgementLineTexture;
    sf::Texture noteRouteSTexture;
    sf::Texture noteRouteDTexture;
    sf::Texture noteRouteFTexture;
    sf::Texture noteRouteSpace1Texture;
    sf::Texture noteRouteSpace2Texture;
    sf::Texture noteRouteJTexture;
    sf::Texture noteRouteKTexture;
    sf::Texture noteRouteLTexture;
    sf::Texture noteRoutePressedTexture;
    sf::Texture noteRouteLineTexture;
    sf::Texture noteBasicTexture;
  
    void loadTextures(); // �� �Լ��� �߰��Ͽ� �ؽ�ó�� �ε��ϵ��� ��

    void initNotes();
    void updateNotes();
    void drawNotes();
    void handleInput();
    void handleKeyRelease(sf::Keyboard::Key key);

    void pressS();
    void releaseS();
    void pressD();
    void releaseD();
    void pressF();
    void releaseF();
    void pressSpace();
    void releaseSpace();
    void pressJ();
    void releaseJ();
    void pressK();
    void releaseK();
    void pressL();
    void releaseL();

    void displayButtons();
    void displayBackground();
    //void displayNoteRouteLines();
    void displayGameInfo();
    void displayNotes();
    void displayJudgementLine();
};
