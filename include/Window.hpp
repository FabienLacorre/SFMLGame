#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Sprite.hpp"

class Window {
public:
    Window(int x, int y);
    ~Window();

    sf::RenderWindow &GetWindow();
    void DrawSprite(Sprite &s);
    void Display();
    void Clear();
    const bool IsOpen() const;
    void Close();
private:
    sf::RenderWindow window;
};

#endif