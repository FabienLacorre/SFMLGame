#include "Window.hpp"

Window::Window(int x, int y){
    this->window = new sf::RenderWindow(sf::VideoMode(x, y), "THIS IS WORKS");
    this->window->setFramerateLimit(30);
    std::cout << "window creation" << std::endl;
}

Window::~Window(){

}

sf::RenderWindow *Window::GetWindow(){
    return this->window;
}

bool Window::IsOpen(){
    return this->window->isOpen();
}
