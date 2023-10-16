#include "Player.hpp"
#include <iostream>
Player::Player(int x, int y, int hp, float speed, float damage, int sizex, int sizey){
    player_shape.setFillColor(sf::Color::Red);
    player_shape.setSize(sf::Vector2f(sizex,sizey));
    player_shape.setPosition(x-(sizex/2), y-(sizey/2));
    this->x = x;
    this->y = y;
    this->hitpoints = hp;
    this->speed = speed;
    this->damage = damage;
}
void Player::prnt(){
    
}
void Player::draw(sf::RenderWindow &w){
    
    w.draw(player_shape);
}
void Player::move(int xx, int yy){
    this->player_shape.move(xx, yy);
    x += xx;
    y += yy;
}
