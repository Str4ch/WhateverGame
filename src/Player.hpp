#ifndef Player_hpp
#define Player_hpp

#include <map>
#include <utility>
#include <SFML/Graphics.hpp>

#include "WeaponCells.hpp"
#include "Weapon.hpp"

using enum Loot_inside;

class Player{
public:
    float x,y,speed;
    int hitpoints,room_pos;
    bool is_atacking;
    sf::RectangleShape player_shape;
    
    std::map <int, std::pair<Loot_inside, void*> > pl_weapons;
    
    int weapon_rn;
    void* player_weapons[4];
    WeaponCells* weapon_cells;
    
    void get_damage(int mob_dmg);
    
    Player(float x, float y, int hp, float speed, int sizex, int sizey);
    void draw(sf::RenderWindow &w);
    void move(float xx, float yy, float dir_x, float dir_y);
    void pick_weapon();
};
#endif /* Player_hpp */
