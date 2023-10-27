#include "Player.hpp"
#include <iostream>
Player::Player(float x, float y, int hp, float speed, int damage, int sizex, int sizey){
    player_shape.setFillColor(sf::Color::Red);
    player_shape.setSize(sf::Vector2f(sizex,sizey));
    player_shape.setPosition(x-(sizex/2), y-(sizey/2));
    this->x = x;
    this->y = y;
    this->hitpoints = hp;
    this->speed = speed;
    this->damage = damage;
}
void Player::draw(sf::RenderWindow &w){
    w.draw(player_shape);
}

void Player::get_damage(int mob_dmg){
    this->hitpoints-=mob_dmg;
    if(this->hitpoints<0)std::cout<<"u died"<<std::endl;
}
void Player::move(float xx, float yy){
    this->player_shape.move(xx, yy);
    x += xx;
    y += yy;
}
