#ifndef Weapon_hpp
#define Weapon_hpp

#include <SFML/Graphics.hpp>
#include "globalvariables.hpp"

class Weapon{
public:
    int damage;
    
    float x,y;
    
    sf::Vector2<int> direction;
    
    sf::Sprite weapon_sp;
    
    //void move(float x, float y);
    void draw(sf::RenderWindow& w);
};

class Sword:public Weapon{
public:
    //void draw(sf::RenderWindow& w);
    void move(float x, float y, float dir_x, float dir_y);

    Sword();
    Sword(float x,float y,int dmg,sf::Vector2<int> dr);
    ~Sword();
};

class Axe:public Weapon{
public:
    //void draw(sf::RenderWindow& w);
    void move(float x, float y, float dir_x, float dir_y);
    void move(float x, float y);
    void attack(float degree);
    Axe();
    Axe(float x, float y,int dmg, sf::Vector2<int> dr);
    ~Axe();
};

class Bow:public Weapon{
public:
    //void draw(sf::RenderWindow& w);
    int dir_cache;
    void move(float x, float y, float dir_x);
    Bow();
    Bow(float x, float y,int dmg, sf::Vector2<int> dr);
    ~Bow();
};

class Punch:public Weapon{
public:
    //void draw(sf::RenderWindow& w);
    
    Punch();
    Punch(float x, float y,int dmg, sf::Vector2<int> dr);
    ~Punch();
};
#endif /* Weapon_hpp */
