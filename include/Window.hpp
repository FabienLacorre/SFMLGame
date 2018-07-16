#include <iostream>
#include <SFML/Graphics.hpp>
#include "Sprite.hpp"

class Window {
public:
    Window(int x, int y);
    ~Window();

    sf::RenderWindow *GetWindow();
    void Draw(Sprite &s);
    void Display();
    void Clear();
    bool IsOpen();
    void Close();
private:
    sf::RenderWindow *window;
};
