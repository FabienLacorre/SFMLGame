#include <SFML/Graphics.hpp>
#include <list>
#include "Entity.hpp"
#include "Window.hpp"
#include "Sprite.hpp"
#include "TextureLoader.hpp"
#include "Panel.hpp"
#include "PanelMenu.hpp"
#include "PanelGame.hpp"

// A VIRER APRES -- JUSTE POUR AVOIR UN BACKGROUND EN ATTENDANT //
void DrawBackground(Window &win, Entity &grass){
// 37 fois 16 pour avoir taille de la window //
    for (int i = 0; i < 37; i++){
        for (int j = 0; j < 37; j++) {
            grass.SetPosition(i * 16, j * 16);
            win.DrawSprite(grass.GetSprite());
        }
    }
}
// ----------------- //

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

    // CREATE PANELS //
    std::list <Panel*>lPanel;
    Panel *pan = new Panel(false, false, win, textureLoader);
    PanelMenu *pan2 = new PanelMenu(false, false, win, textureLoader);
    PanelGame *mainPanel = new PanelGame(false, false, win, textureLoader);

    lPanel.push_back(pan);
    lPanel.push_back(pan2);
    lPanel.push_back(mainPanel);
    // ----- //

    // TEST EXECUTION PANELS //
    for (auto elem : lPanel){
        elem->Run();
    }
    // ----- //

    while (win.IsOpen()){
        sf::Event event;
        while (win.GetWindow().pollEvent(event)){
            if (event.type == sf::Event::Closed){
                win.Close();
            }
        }

        // TOUCH EVENT //
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            win.Close();
        }
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

    // DESTROY PANELS //
    for (auto elem : lPanel){
        delete elem;        
    }
    // ----- //
    return 0;
}
