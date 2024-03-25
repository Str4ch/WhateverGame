#ifndef WHATEVERGAME_WEAPONCELLS_HPP
#define WHATEVERGAME_WEAPONCELLS_HPP

#include <SFML/Graphics.hpp>
#include "globalvariables.hpp"

class WeaponCells {
    float x, y, size_x, size_y;
    std::string cell_num;
    bool weapon_picked;


    sf::RectangleShape chosen;
    sf::RectangleShape border;
    sf::RectangleShape cell;
    sf::Sprite weapon_inside;

    sf::Text draw_cell_num;
public:
    WeaponCells();
    WeaponCells(float x, float y, float size_x, float size_y, std::string cell_num);

    bool is_chosen;

    void draw(sf::RenderWindow &w);
    void move(float x, float y);
    void set_weapon_inside(sf::Sprite &w_i);

    ~WeaponCells();
};


#endif