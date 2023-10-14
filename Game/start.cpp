#include <SFML/Graphics.hpp>

int main()
{
    using namespace sf;

    // â ����
    RenderWindow window(VideoMode(1500, 843), "���� ����");

    // �̹��� �ε�
    Texture texture;
    if (!texture.loadFromFile("images/start_backgroud.png")) {
        // �̹����� �ε��ϴ� �� ������ ����� ���� �޽��� ���
        return 1;
    }

    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(0, 0); // �̹����� ��ġ ����

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite); // �̹����� ȭ�鿡 �׸��ϴ�.
        window.display();
    }

    return 0;
}
