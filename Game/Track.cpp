#include <string>

class Track {
private:
    std::string titleImage; // ���� �κ� �̹���
    std::string startImage; // ���� ���� â ǥ�� �̹���
    std::string gameImage; // �ش� ���� �������� �� ǥ�� �̹���
    std::string startMusic; // ���� ���� â ����
    std::string gameMusic; // �ش� ���� �������� �� ����
    std::string titleName; // �� ����

public:
    // ������
    Track(const std::string& titleImage, const std::string& startImage, const std::string& gameImage,
        const std::string& startMusic, const std::string& gameMusic, const std::string& titleName)
        : titleImage(titleImage), startImage(startImage), gameImage(gameImage),
        startMusic(startMusic), gameMusic(gameMusic), titleName(titleName) {}

    // Getter �� Setter �Լ���
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
