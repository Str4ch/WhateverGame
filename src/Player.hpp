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
    int x;
    int y;
    int hitpoints;
    float speed;
    float damage;
    sf::RectangleShape player_shape;
    void get_damage(int mob_dmg);
    

    
    Player(int x, int y, int hp, float speed, float damage, int sizex, int sizey);
    void prnt();
    void draw(sf::RenderWindow &w);
    void move(int xx, int yy);
};
#endif /* Player_hpp */
