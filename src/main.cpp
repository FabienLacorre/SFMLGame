#include <SFML/Graphics.hpp>
#include "Window.hpp"

void Update(Window *win){
    win->GetWindow()->clear();
    win->GetWindow()->display();
}

int main() {

    Window *win = new Window(600, 600);

    while (win->IsOpen()){
        sf::Event event;
        while (win->GetWindow()->pollEvent(event)){
            if (event.type == sf::Event::Closed){
                win->GetWindow()->close();
            }
        }
        Update(win);
    }
    return 0;
}
