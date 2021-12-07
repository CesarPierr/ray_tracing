#include <SFML/OpenGL.hpp>


int main(){
    sf::Window window(sf::VideoMode(800, 600), "OpenGL");

    // it works out of the box
    glEnable(GL_TEXTURE_2D);
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;

    sf::Window window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, settings);
    return 0;
}
