//
//  Enemy.cpp
//  WhateverGame
//
//  Created by Алексей Шмаков on 20.10.2023.
//

#include "Enemy.hpp"

Enemy::Enemy(int hp, int dmg, int e_t, float x, float y, float sp){
    hitpoints = hp;
    damage = dmg;
    enemy_type = e_t;
    this->x = x;
    this->y = y;
    speed = sp;
    
    enemy_shape.setSize(sf::Vector2f(10,25));
    enemy_shape.setPosition(x, y);
    enemy_shape.setFillColor(global::floor);
    
}
void Enemy::get_damage(int dmg){
    hitpoints-=dmg;
}


void Enemy::draw(sf::RenderWindow &w){
    w.draw(enemy_shape);
}

void Enemy::move(float x, float y){
    enemy_shape.move(x,y);
    this->x+=x;
    this->y+=y;
}
