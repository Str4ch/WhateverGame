#ifndef globalvariables_hpp
#define globalvariables_hpp
#include "SFML/Graphics.hpp"

namespace global {
    extern sf::VideoMode resolution;
    extern sf::Color floor;
    extern sf::Color wall;
    extern sf::Color corner;
    extern sf::Color door;

    extern sf::Texture corner_texture;
    extern sf::Texture wall_texture;
    extern sf::Texture floor_texture;
    extern sf::Texture door_texture;
    extern sf::Texture hole_texture;
    extern sf::Texture chest_texture;
    extern sf::Texture sword_texture;
    extern sf::Texture axe_texture;
    extern sf::Texture bow_texture;
}

void set_evrth();

#endif /* globalvariables_hpp */
