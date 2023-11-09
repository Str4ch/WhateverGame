#include "Weapon.hpp"

void Weapon::draw(sf::RenderWindow &w){
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
    weapon_sp.setTexture(global::axe_texture);
}
Axe::Axe(float x,float y,int dmg,sf::Vector2<int> dr){
    this->x = x;
    this->y = y;
    damage = dmg;
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
