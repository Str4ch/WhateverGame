//
//  Player.hpp
//  WG
//
//  Created by Алексей Шмаков on 09.10.2023.
//

#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics.hpp>

class Player{
public:
    float x;
    float y;
    int hitpoints;
    float speed;
    float damage;
    sf::RectangleShape player_shape;
    void get_damage(float mob_dmg);
    

    
    Player(float x, float y, int hp, float speed, float damage, int sizex, int sizey);
    void prnt();
    void draw(sf::RenderWindow &w);
    void move(float xx, float yy);
};
#endif /* Player_hpp */
