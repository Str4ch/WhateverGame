#include "globalvariables.hpp"

namespace global {
    double math_pi = 3.1415;
    sf::VideoMode resolution(1280, 720);
    sf::Color floor(210,183,115);
    sf::Color wall(247,186,11);
    sf::Color corner(200,159,4);
    sf::Color door(226,176,7);

    sf::Texture corner_texture;
    sf::Texture wall_texture;
    sf::Texture floor_texture;
    sf::Texture door_texture;
    sf::Texture chest_texture;
    sf::Texture hole_texture;
    sf::Texture sword_texture;
    sf::Texture axe_texture;
    sf::Texture bow_texture;
    sf::Texture punch_texture;

    //enum Loot_inside;
}

void set_evrth(){
    global::corner_texture.loadFromFile("sprites/corner.png");
    global::wall_texture.loadFromFile("sprites/wall.png");
    global::floor_texture.loadFromFile("sprites/floor.png");
    global::door_texture.loadFromFile("sprites/door.png");
    global::chest_texture.loadFromFile("sprites/chest.png");
    global::hole_texture.loadFromFile("sprites/hole.png");
    global::sword_texture.loadFromFile("sprites/sword.png");
    global::axe_texture.loadFromFile("sprites/axe.png");
    global::bow_texture.loadFromFile("sprites/bow.png");
    global::punch_texture.loadFromFile("sprites/punch.png");
    
    global::wall_texture.setRepeated(true);
    global::floor_texture.setRepeated(true);
    global::door_texture.setRepeated(true);
    
    /*enum Loot_inside{
        SWORD,
        AXE,
        BOW,
        PUNCH
    };*/
}


