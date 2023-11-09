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
    Sword();
    Sword(float x,float y,int dmg,sf::Vector2<int> dr);
    ~Sword();
};

class Axe:Weapon{
    Axe();
    Axe(float x, float y,int dmg, sf::Vector2<int> dr);
    ~Axe();
};

class Bow:Weapon{
    Bow();
    Bow(float x, float y,int dmg, sf::Vector2<int> dr);
    ~Bow();
};

class Punch:Weapon{
    Punch();
    Punch(float x, float y,int dmg, sf::Vector2<int> dr);
    ~Punch();
};
#endif /* Weapon_hpp */
