#include "Chest.hpp"
#include "globalvariables.hpp"
#include <iostream>

Chest::Chest(){}
Chest::Chest(float x, float y){
    chest_sp.setTexture(global::chest_texture);
    chest_sp.setPosition(x, y);
    
    int r = random()%4;
    switch(r){
        case 0:
            lt = Loot_inside::SWORD;
            weapon_inside = new Sword(x+50,y+50, 12, sf::Vector2<int>(1,1));//x+50,y+50,sf::Vector2<int>(1,1));
            break;
        case 1:
            lt = Loot_inside::AXE;
            weapon_inside = new Axe(x+100,y+100, 12, sf::Vector2<int>(1,1));
            break;
        case 2:
            lt = Loot_inside::BOW;
            weapon_inside = new Bow(x+50,y+50, 12, sf::Vector2<int>(1,1));
            break;
        case 3:
            lt = Loot_inside::PUNCH;
            weapon_inside = new Punch(x+50,y+50, 12, sf::Vector2<int>(1,1));
            break;
    }
    //*weapon_inside = Weapon(x+50,y+50,rand()%3+1,sf::Vector2<int>(1,1));
    is_open = false;
    weapon_is_picked = false;
}

void Chest::draw(sf::RenderWindow &w){
    w.draw(chest_sp);
    if(is_open && !weapon_is_picked){
        switch(lt){
            case SWORD:
                (static_cast<Sword*>(weapon_inside))->draw(w);
                break;
            case AXE:
                (static_cast<Axe*>(weapon_inside))->draw(w);
                break;
            case BOW:
                (static_cast<Bow*>(weapon_inside))->draw(w);
                break;
            case PUNCH:
                (static_cast<Punch*>(weapon_inside))->draw(w);
                break;
        }
    }
}

void Chest::open(Player& m_p){
    if(m_p.player_shape.getGlobalBounds().intersects(chest_sp.getGlobalBounds())) is_open = !is_open;
}

std::pair<Loot_inside, void*> Chest::pick(Player &m_p){
    
    if((!weapon_is_picked) && is_open){
        //std::cout<<static_cast<Weapon*>(weapon_inside)->weapon_sp.getGlobalBounds().left;
        if(m_p.player_shape.getGlobalBounds().intersects(static_cast<Weapon*>(weapon_inside)->weapon_sp.getGlobalBounds())){
            weapon_is_picked = true;
            switch (lt) {
                case AXE:
                    std::cout<<static_cast<Weapon*>(weapon_inside)->weapon_sp.getGlobalBounds().left;
                    //m_p.pl_weapons[m_p.weapon_rn].first = AXE;
                    Axe* temp = static_cast<Axe*>(weapon_inside);
                    std::cout<<3;
                    //m_p.pl_weapons[m_p.weapon_rn].second = new Axe(*temp);
                    return std::make_pair(AXE, new Axe(*temp));
                    break;
            }
            
            delete &weapon_inside;
        }
    }
    return m_p.pl_weapons[m_p.weapon_rn];
}

Chest::~Chest(){}
