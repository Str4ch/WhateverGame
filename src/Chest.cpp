#include "Chest.hpp"
#include "globalvariables.hpp"
#include <iostream>
Chest::Chest(){}
Chest::Chest(float x, float y){
    chest_sp.setTexture(global::chest_texture);
    chest_sp.setPosition(x, y);
    weapon_inside = new Weapon();
    int r = random()%4;
    switch(r){
        case 0:
            weapon_inside = new Sword();
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
    }
    //*weapon_inside = Weapon(x+50,y+50,rand()%3+1,sf::Vector2<int>(1,1));
    is_open = false;
    weapon_is_picked = false;
}

void Chest::draw(sf::RenderWindow &w){
    w.draw(chest_sp);
    //std::cout<<sizeof(*weapon_inside)<<std::endl;
    if(is_open && !weapon_is_picked){
        (*(Sword*)weapon_inside)->draw(w);
    }
}

void Chest::open(Player& m_p){
    if(m_p.player_shape.getGlobalBounds().intersects(chest_sp.getGlobalBounds())) is_open = !is_open;
    
}
Weapon Chest::pick(Player &m_p){
    
    if((!weapon_is_picked) && is_open){
        //std::cout<<sizeof(*weapon_inside)<<std::endl;
        if(m_p.player_shape.getGlobalBounds().intersects((weapon_inside)->weapon_sp.getGlobalBounds())){
            int tp = weapon_inside->type;
            std::cout<<sizeof(*weapon_inside)<<std::endl;
            weapon_is_picked = true;
            delete (weapon_inside);
            return Weapon(m_p.x,m_p.y,tp,sf::Vector2(1,1));
            
        }
    }
    return Weapon(0,0,0,sf::Vector2(1,1));
}

Chest::~Chest(){}
