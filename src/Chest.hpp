#ifndef Chest_hpp
#define Chest_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Weapon.hpp"
#include "Player.hpp"
class Chest{
public:
    float x,y;
    bool is_open;
    sf::Sprite chest_sp;
    
    Weapon* weapon_inside;
    bool weapon_is_picked;
    Chest();
    Chest(float x, float y);
    ~Chest();
    
    void open(Player& m_p);
    void draw(sf::RenderWindow& w);
    Weapon pick(Player& m_p);
};
#endif /* Chest_hpp */
