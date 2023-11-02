//
//  Player.hpp
//  WG
//
//  Created by Алексей Шмаков on 09.10.2023.
//

#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics.hpp>
#include "Weapon.hpp"


class Player{
public:
    float x,y,speed;
    int hitpoints,room_pos;
    sf::RectangleShape player_shape;
    
    Weapon* player_weapons;
    
    void get_damage(int mob_dmg);
    

    
    Player(float x, float y, int hp, float speed, int sizex, int sizey);
    void draw(sf::RenderWindow &w);
    void move(float xx, float yy);
    void pick_weapon();
};
#endif /* Player_hpp */
