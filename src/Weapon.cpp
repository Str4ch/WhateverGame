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

    weapon_sp.setTexture(global::sword_texture);
    weapon_sp.setOrigin(5, 0);
    weapon_sp.setPosition(x, y);

    damage = dmg;
}
void Sword::move(float x, float y, float dir_x, float dir_y) {
    float pos_x = x - 20*dir_x;
    float pos_y = y - 50*dir_y-25;
    weapon_sp.setPosition(pos_x, pos_y);
    this->x=pos_x;
    this->y=pos_y;
}
Sword::~Sword(){}

Axe::Axe(){}
Axe::Axe(float x,float y,int dmg,sf::Vector2<int> dr){
    this->x = x;
    this->y = y;
    weapon_sp.setTexture(global::axe_texture);
    weapon_sp.setOrigin(5, 50);
    weapon_sp.setPosition(x, y);
    
    damage = dmg;
}

void Axe::move(float x, float y, float dir_x, float dir_y){
    float pos_x = x + 10*dir_x;
    float pos_y = y + 25*dir_y;
    weapon_sp.setPosition(pos_x, pos_y);
    this->x=pos_x;
    this->y=pos_y;
    weapon_sp.setRotation(dir_x==0 && dir_y == 1?180:((acos((dir_x*0-dir_y*1)/pow(dir_x*dir_x + dir_y*dir_y, 0.5))*180/global::math_pi)*dir_x));
}

void Axe::move(float x, float y){
    weapon_sp.setPosition(x, y);
    this->x=x;
    this->y=y;
}

void Axe::attack(float degree) {
    weapon_sp.rotate(degree);
}
Axe::~Axe(){}

Bow::Bow(){
    weapon_sp.setTexture(global::bow_texture);
}
Bow::Bow(float x,float y,int dmg,sf::Vector2<int> dr){
    this->x = x;
    this->y = y;

    weapon_sp.setTexture(global::bow_texture);
    weapon_sp.setOrigin(5, 50);
    weapon_sp.setPosition(x, y);

    damage = dmg;
}
void Bow::move(float x, float y, float dir_x) {


    if(dir_x!=0){
        dir_cache = dir_x;
        weapon_sp.setPosition(x-dir_x*15, y-25);
        weapon_sp.setScale(dir_x, 1);
    }
    else{
        weapon_sp.setPosition(x-dir_cache*15, y-25);
    }
    this->x=x;
    this->y=y;
}
Bow::~Bow(){}

Punch::Punch(){}
Punch::Punch(float x,float y,int dmg,sf::Vector2<int> dr){
    this->x = x;
    this->y = y;
    damage = dmg;
}

Punch::~Punch(){}
