#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include <chrono>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "globalvariables.hpp"

#include "Player.hpp"

class Enemy{
public:
    int hitpoints,damage,enemy_type;
    sf::RectangleShape enemy_shape;
    
    std::chrono::duration<float> pause;//pause between the hits
    
    float x,y,speed;
    Enemy();
    Enemy(int hp, int dmg, int e_t, float x, float y, float speed);
    ~Enemy();
    
    void get_damage(int dmg);
    void draw(sf::RenderWindow &w);
    void move(float x, float y);
    void hit_player(Player& m_p);
};

#endif /* Enemy_hpp */
