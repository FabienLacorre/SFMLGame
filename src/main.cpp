#include <SFML/Graphics.hpp>
#include <list>
#include "Entity.hpp"
#include "Window.hpp"
#include "Sprite.hpp"
#include "TextureLoader.hpp"
#include "Panel.hpp"
#include "PanelMenu.hpp"
#include "PanelGame.hpp"

void CatchEnd(sf::Event &event, Window &win){
    while (win.GetWindow().pollEvent(event)){
        if (event.type == sf::Event::Closed){
            win.Close();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        win.Close();
    }
}

void DeletePanels(std::list<Panel*> &lPanels){
    for (auto elem : lPanels){
        delete elem;        
    }
}

void ExecutePanels(std::list<Panel*> &lPanels, sf::Event &event, sf::Clock &clock){
    for (auto pan : lPanels){
        pan->Run(event, clock);
    }
}

void RestartClock(sf::Clock &clock){
    if (clock.getElapsedTime().asSeconds() > 0.15f){
        clock.restart();
    }
}

int main() {
    Window win(592, 592);

    TextureLoader textureLoader;
    textureLoader.PushTexture("fountain", "./img/zeldaLikeSprite/fountain.png");
    textureLoader.PushTexture("player", "./img/zeldaLikeSprite/playerSprites.png");
    textureLoader.PushTexture("grass", "./img/zeldaLikeSprite/grass.png");

    std::list <Panel*>lPanels;
    lPanels.push_back(new Panel(false, false, win, textureLoader));
    lPanels.push_back(new PanelMenu(false, false, win, textureLoader));
    lPanels.push_back(new PanelGame(false, false, win, textureLoader));

    sf::Event event;
    sf::Clock clock;
    
    while (win.IsOpen()){
        win.Clear();
        CatchEnd(event, win);
        ExecutePanels(lPanels, event, clock);
        RestartClock(clock);
        win.Display();
    }
    DeletePanels(lPanels);
    return 0;
}
