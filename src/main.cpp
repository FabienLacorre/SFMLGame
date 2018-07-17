#include <SFML/Graphics.hpp>
#include "Window.hpp"

int main() {
    Window win(600, 600);
    Sprite s("./img/zeldaLikeSprite/playerSprites.png");
    sf::IntRect rect(0,0,16,22);
    sf::Clock clock;

    while (win.IsOpen()){
        sf::Event event;
        while (win.GetWindow().pollEvent(event)){
            if (event.type == sf::Event::Closed){
                win.Close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            if (clock.getElapsedTime().asSeconds() > 0.1f){
                rect.top = 0;
                rect.left += 16;
                if (rect.left >= 64) {
                    rect.left = 0;
                }
                s.GetSprite().setTextureRect(rect);
                s.MoveSprite(3, "bottom");
                clock.restart();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            if (clock.getElapsedTime().asSeconds() > 0.1f){
                rect.left += 16;
                rect.top = 44;
                if (rect.left >= 64) {
                    rect.left = 0;
                }
                s.GetSprite().setTextureRect(rect);
                s.MoveSprite(3, "top");
                clock.restart();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
            if (clock.getElapsedTime().asSeconds() > 0.1f){
                rect.left += 16;
                rect.top = 66;
                if (rect.left >= 64) {
                    rect.left = 0;
                }
                s.GetSprite().setTextureRect(rect);
                s.MoveSprite(3, "left");
                clock.restart();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            if (clock.getElapsedTime().asSeconds() > 0.1f){
                rect.left += 16;
                rect.top = 22;
                if (rect.left >= 64) {
                    rect.left = 0;
                }
                s.GetSprite().setTextureRect(rect);
                s.MoveSprite(3, "right");
                clock.restart();
            }
        }
        win.Clear();
        win.DrawSprite(s);
        win.Display();
    }
    return 0;
}
