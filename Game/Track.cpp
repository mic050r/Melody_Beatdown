#include <string>

class Track {
private:
    std::string titleImage; // 제목 부분 이미지
    std::string startImage; // 게임 선택 창 표지 이미지
    std::string gameImage; // 해당 곡을 실행했을 때 표지 이미지
    std::string startMusic; // 게임 선택 창 음악
    std::string gameMusic; // 해당 곡을 실행했을 때 음악
    std::string titleName; // 곡 제목

public:
    // 생성자
    Track(const std::string& titleImage, const std::string& startImage, const std::string& gameImage,
        const std::string& startMusic, const std::string& gameMusic, const std::string& titleName)
        : titleImage(titleImage), startImage(startImage), gameImage(gameImage),
        startMusic(startMusic), gameMusic(gameMusic), titleName(titleName) {}

    // Getter 및 Setter 함수들
    const std::string& getTitleImage() const {
        return titleImage;
    }

    void setTitleImage(const std::string& titleImage) {
        this->titleImage = titleImage;
    }

    const std::string& getStartImage() const {
        return startImage;
    }

    void setStartImage(const std::string& startImage) {
        this->startImage = startImage;
    }

    const std::string& getGameImage() const {
        return gameImage;
    }

    void setGameImage(const std::string& gameImage) {
        this->gameImage = gameImage;
    }

    const std::string& getStartMusic() const {
        return startMusic;
    }

    void setStartMusic(const std::string& startMusic) {
        this->startMusic = startMusic;
    }

    const std::string& getGameMusic() const {
        return gameMusic;
    }

    void setGameMusic(const std::string& gameMusic) {
        this->gameMusic = gameMusic;
    }

    const std::string& getTitleName() const {
        return titleName;
    }

    void setTitleName(const std::string& titleName) {
        this->titleName = titleName;
    }
};
