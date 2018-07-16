#include <SFML/Graphics.hpp>
#include "Window.hpp"

int main() {
    Window win(600, 600);
    Sprite s("./img/megaman.png");
    while (win.IsOpen()){
        sf::Event event;
        while (win.GetWindow().pollEvent(event)){
            if (event.type == sf::Event::Closed){
                win.Close();
            }
        }
        win.Clear();
        win.Draw(s);
        win.Display();
    }
    return 0;
}
