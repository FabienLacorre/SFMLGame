#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Window.hpp"
#include "Sprite.hpp"
#include "TextureLoader.hpp"

void DrawBackground(Window &win, Entity &grass){
// 37 fois 16 pour avoir taille de la window //
    for (int i = 0; i < 37; i++){
        for (int j = 0; j < 37; j++) {
            grass.SetPosition(i * 16, j * 16);
            win.DrawSprite(grass.GetSprite());
        }
    }
}

int main() {
    Window win(592, 592);
    sf::Clock clock;
    TextureLoader textureLoader;

    textureLoader.PushTexture("fountain", "./img/zeldaLikeSprite/fountain.png");
    textureLoader.PushTexture("player", "./img/zeldaLikeSprite/playerSprites.png");
    textureLoader.PushTexture("grass", "./img/zeldaLikeSprite/grass.png");
    Entity player(textureLoader.GetImage("player"), 2, 16, 22, 300, 300, 2);
    Entity grass(textureLoader.GetImage("grass"), 2, 16, 16, 50, 50, 0);
    Entity fountain(textureLoader.GetImage("fountain"), 2, 48, 45, 50, 50, 0);

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

        // STATICK SPRITE MOVEMENT //
        fountain.SpriteSheetMovement(clock, 0, 3);
        // ----- //

        // CLOCK //
        if (clock.getElapsedTime().asSeconds() > 0.15f){
            clock.restart();
        }
        // ----- //

        // DISPLAY //
        win.Clear();
        DrawBackground(win, grass);
        win.DrawSprite(fountain.GetSprite());
        win.DrawSprite(player.GetSprite());
        win.Display();
        // ----- //
    }
    return 0;
}
