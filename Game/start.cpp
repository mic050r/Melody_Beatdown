#include <SFML/Graphics.hpp>

int main()
{
    using namespace sf;

    // 창 생성
    RenderWindow window(VideoMode(1500, 843), "리듬 게임");

    // 이미지 로드
    Texture texture;
    if (!texture.loadFromFile("images/start_backgroud.png")) {
        // 이미지를 로드하는 데 문제가 생기면 오류 메시지 출력
        return 1;
    }

    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(0, 0); // 이미지의 위치 설정

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite); // 이미지를 화면에 그립니다.
        window.display();
    }

    return 0;
}
