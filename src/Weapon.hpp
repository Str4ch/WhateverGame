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
    
    void draw(sf::RenderWindow& w);
    
};

class Sword:Weapon{
public:
    void draw(sf::RenderWindow& w);
    
    Sword();
    Sword(float x,float y,int dmg,sf::Vector2<int> dr);
    ~Sword();
};

class Axe:Weapon{
public:
    Axe();
    Axe(float x, float y,int dmg, sf::Vector2<int> dr);
    ~Axe();
};

class Bow:Weapon{
public:
    Bow();
    Bow(float x, float y,int dmg, sf::Vector2<int> dr);
    ~Bow();
};

class Punch:Weapon{
public:
    Punch();
    Punch(float x, float y,int dmg, sf::Vector2<int> dr);
    ~Punch();
};
#endif /* Weapon_hpp */
