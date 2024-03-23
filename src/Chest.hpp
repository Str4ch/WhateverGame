#ifndef Chest_hpp
#define Chest_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Weapon.hpp"
#include "Player.hpp"

using enum Loot_inside;

class Chest{
public:
    float x,y;
    bool is_open;
    sf::Sprite chest_sp;
    Loot_inside lt;
    void* weapon_inside;//'''TODO make random loot and make the health poisons'
    bool weapon_is_picked;
    Chest();
    Chest(float x, float y);
    ~Chest();
    
    void open(Player& m_p);
    void draw(sf::RenderWindow& w);
    std::pair<Loot_inside, void*> pick(Player& m_p);
};

#endif /* Chest_hpp */
