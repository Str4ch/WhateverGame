#include "Player.hpp"
#include <iostream>
Player::Player(float x, float y, int hp, float speed, int sizex, int sizey){
    player_shape.setFillColor(sf::Color::Red);//temporary
    
    player_shape.setSize(sf::Vector2f(sizex,sizey));
    player_shape.setPosition(x-(sizex/2), y-(sizey/2));
    player_shape.setOrigin(5, 12.5);
    this->x = x;
    this->y = y;
    this->hitpoints = hp;
    this->speed = speed;
    is_atacking = false;
    weapon_rn = 0;
    weapon_cells = new WeaponCells[4];
    std::cout<<1<<std::endl;
    for(int i = 0; i < 4; i++){
        weapon_cells[i] = WeaponCells(i*25 +x - global::resolution.width/8 + 5, y - global::resolution.height/8 + 5, 20, 20, std::to_string(i+1));
    };
}
void Player::draw(sf::RenderWindow &w){
    w.draw(player_shape);
    for(int i = 0; i < 4;i++){
        weapon_cells[i].draw(w);
    }
    if (pl_weapons[weapon_rn].first != 0){
        if(is_atacking){
            (static_cast<Axe*>(pl_weapons[weapon_rn].second))->attack(1);
        }
        (static_cast<Weapon*>(pl_weapons[weapon_rn].second))->draw(w);
    }
}

void Player::get_damage(int mob_dmg){
    this->hitpoints-=mob_dmg;
    if(this->hitpoints<0);//std::cout<<"u died"<<std::endl;//TODO
}
void Player::move(float xx, float yy, float dir_x, float dir_y){
    
    this->player_shape.move(xx, yy);
    
    x += xx;
    y += yy;
    for(int i = 0;i < 4;i++){
        weapon_cells[i].move(xx,yy);
    }

    switch (pl_weapons[weapon_rn].first) {
        case AXE:
            if(is_atacking){
                (static_cast<Axe *>(pl_weapons[weapon_rn].second))->move(x, y);
            }
            else (static_cast<Axe *>(pl_weapons[weapon_rn].second))->move(x, y, dir_x, dir_y);
            break;
        case BOW:
            if(is_atacking){
                //(static_cast<Bow*>(pl_weapons[weapon_rn].second))->move(x, y);
            }
            else (static_cast<Bow*>(pl_weapons[weapon_rn].second))->move(x+5, y, dir_x);
            break;
        case SWORD:
            if(is_atacking){
                //(static_cast<Sword*>(pl_weapons[weapon_rn].second))->move(x, y);
            }
            else (static_cast<Sword*>(pl_weapons[weapon_rn].second))->move(x+5, y, dir_x, dir_y);
            break;
    }

        //(static_cast<Weapon*>(my_player.pl_weapons[my_player.weapon_rn].second)->weapon_sp.setPosition(my_player.x+(D-A)*10+5, my_player.y+(S-W)*25+12.5));
        //(static_cast<Axe*>(pl_weapons[weapon_rn].second))->rotate(xx, yy);

    
}
