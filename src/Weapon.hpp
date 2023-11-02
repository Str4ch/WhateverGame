#ifndef Weapon_hpp
#define Weapon_hpp

#include <SFML/Graphics.hpp>
#include "globalvariables.hpp"

class Weapon{
public:
    int type,damage;
    
    float x,y;
    
    bool b_draw;//this var used to indicate if the weapon needs to be drawed (f.e. when you attack someone it is drawn)
    sf::Vector2<int> direction;
    
    sf::Sprite weapon_sp;
    
    Weapon();
    Weapon(float x, float y, int tp, sf::Vector2<int> dr);
    ~Weapon();
    
    void draw(sf::RenderWindow& w);
    
};

#endif /* Weapon_hpp */
