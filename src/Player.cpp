#include "Player.hpp"
#include <iostream>
Player::Player(float x, float y, int hp, float speed, int sizex, int sizey){
    player_shape.setFillColor(sf::Color::Red);
    player_shape.setSize(sf::Vector2f(sizex,sizey));
    player_shape.setPosition(x-(sizex/2), y-(sizey/2));
    this->x = x;
    this->y = y;
    this->hitpoints = hp;
    this->speed = speed;
    
    player_weapons = new Weapon[4];
    for(int i = 0;i<4;i++){
        player_weapons[i] = Weapon(0,0,0,sf::Vector2(0,0));
    }
}
void Player::draw(sf::RenderWindow &w){
    w.draw(player_shape);
    //std::cout<<player_weapons[0].weapon_sp.getTexture();
    w.draw(player_weapons[0].weapon_sp);
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
