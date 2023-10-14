#include <SFML/Graphics.hpp>
#include "game_functions.h"

using namespace sf;

void start() {
    RenderWindow window(VideoMode(1500, 843), "∏ÆµÎ ∞‘¿”");

    Texture texture;
    if (!texture.loadFromFile("images/start_background.png")) {
        return;
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        DisplayBackground(window, texture);

        window.display();
    }
}
