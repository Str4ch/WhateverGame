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
    float x,y,speed;
    int hitpoints,damage,room_pos;
    sf::RectangleShape player_shape;
    void get_damage(int mob_dmg);
    

    
    Player(float x, float y, int hp, float speed, int damage, int sizex, int sizey);
    void draw(sf::RenderWindow &w);
    void move(float xx, float yy);
};
#endif /* Player_hpp */
