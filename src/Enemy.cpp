#include "Enemy.hpp"

Enemy::Enemy(int hp, int dmg, int e_t, float x, float y, float sp){
    hitpoints = hp;
    damage = dmg;
    enemy_type = e_t;
    this->x = x;
    this->y = y;
    speed = sp;
    pause = std::chrono::duration<float> (1);
    enemy_shape.setSize(sf::Vector2f(10,25));
    enemy_shape.setPosition(x, y);
    enemy_shape.setFillColor(global::floor);
    
}

void Enemy::get_damage(Player &m_p){
    if(m_p.pl_weapons[m_p.weapon_rn].first != 0){
        if((static_cast<Axe*>(m_p.pl_weapons[m_p.weapon_rn].second))->weapon_sp.getGlobalBounds().intersects(enemy_shape.getGlobalBounds())){
            hitpoints-=((static_cast<Axe*>(m_p.pl_weapons[m_p.weapon_rn].second))->damage);
        }
    }
}

void Enemy::draw(sf::RenderWindow &w){
    w.draw(enemy_shape);
}

void Enemy::hit_player(Player &m_p){
    std::chrono::time_point tick = std::chrono::steady_clock::now();
    if(m_p.player_shape.getGlobalBounds().intersects(enemy_shape.getGlobalBounds())&& pause.count()*1000>(1)){
        m_p.get_damage(this->damage);
        pause = std::chrono::duration<float> (0);
    }
    
    std::chrono::time_point tack = std::chrono::steady_clock::now();
    pause = std::chrono::duration<float>(tack-tick+pause);
}

void Enemy::move(float x, float y){
    enemy_shape.move(x,y);
    this->x+=x;
    this->y+=y;
}

Enemy::Enemy(){}

Enemy::~Enemy(){}
