#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Window.hpp"
#include "Sprite.hpp"


int main() {
    Window win(600, 600);
    Entity player("./img/zeldaLikeSprite/playerSprites.png", 2, 16, 22, 50, 50, 3);
    sf::Clock clock;

    while (win.IsOpen()){
        sf::Event event;
        while (win.GetWindow().pollEvent(event)){
            if (event.type == sf::Event::Closed){
                win.Close();
            }
        }

        // TOUCH EVENT //
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            player.MoveEntity(clock, player.GetPosition().x, player.GetPosition().y + player.GetVelocity());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            player.MoveEntity(clock, player.GetPosition().x, player.GetPosition().y - player.GetVelocity());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
            player.MoveEntity(clock, player.GetPosition().x - player.GetVelocity(), player.GetPosition().y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            player.MoveEntity(clock, player.GetPosition().x + player.GetVelocity(), player.GetPosition().y);
        }
        // ----- //

        // DISPLAY //
        win.Clear();
        win.DrawSprite(player.GetSprite());
        win.Display();
        // ----- //
    }
    return 0;
}
