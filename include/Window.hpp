#include <iostream>
#include <SFML/Graphics.hpp>

class Window {
public:
    Window(int x, int y);
    ~Window();

    sf::RenderWindow *GetWindow();
    bool IsOpen();
private:
    sf::RenderWindow *window;
};
