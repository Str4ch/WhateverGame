#include "Weapon.hpp"
#include "cmath"
#include <iostream>

void Weapon::draw(sf::RenderWindow &w) {
    w.draw(weapon_sp);
}
Sword::Sword(){
    weapon_sp.setTexture(global::sword_texture);
}
Sword::Sword(float x,float y,int dmg,sf::Vector2<int> dr){
    this->x = x;
    this->y = y;
    damage = dmg;
}

Sword::~Sword(){}

Axe::Axe(){
    //weapon_sp.setTexture(global::axe_texture);
}
Axe::Axe(float x,float y,int dmg,sf::Vector2<int> dr){
    this->x = x;
    this->y = y;
    weapon_sp.setTexture(global::axe_texture);
    weapon_sp.setOrigin(5, 50);
    weapon_sp.setPosition(x, y);
    
    damage = dmg;
}

void Axe::move(float x, float y, float dir_x, float dir_y){
    //my_player.x+(D-A)*10+5, my_player.y+(S-W)*25+12.5));
    float pos_x = x + 10*dir_x;
    float pos_y = y + 25*dir_y;
    weapon_sp.setPosition(pos_x, pos_y);
    this->x=pos_x;
    this->y=pos_y;
    weapon_sp.setRotation(dir_x==0 && dir_y == 1?180:((acos((dir_x*0-dir_y*1)/pow(dir_x*dir_x + dir_y*dir_y, 0.5))*180/global::math_pi)*dir_x));
}

Axe::~Axe(){}

Bow::Bow(){
    weapon_sp.setTexture(global::bow_texture);
}
Bow::Bow(float x,float y,int dmg,sf::Vector2<int> dr){
    this->x = x;
    this->y = y;
    damage = dmg;
}

Bow::~Bow(){}

Punch::Punch(){}
Punch::Punch(float x,float y,int dmg,sf::Vector2<int> dr){
    this->x = x;
    this->y = y;
    damage = dmg;
}

Punch::~Punch(){}
