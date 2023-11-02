//
//  Weapon.cpp
//  WG
//
//  Created by Алексей Шмаков on 28.10.2023.
//

#include "Weapon.hpp"
Weapon::Weapon(){}
Weapon::Weapon(float x, float y, int tp, sf::Vector2<int> dr){
    this->x = x;
    this->y = y;
    type = tp;
    direction = dr;
    weapon_sp.setPosition(x, y);
    weapon_sp.setTexture(global::sword_texture);
    weapon_sp.setTextureRect(sf::IntRect(0,0,10,50));
}
Weapon::~Weapon(){}
void Weapon::draw(sf::RenderWindow &w){
    w.draw(weapon_sp);
}
