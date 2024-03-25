#include "WeaponCells.hpp"
#include <iostream>

WeaponCells::WeaponCells(float x, float y, float size_x, float size_y, std::string cell_num) {
    this->x = x;
    this->y = y;
    this->cell_num = cell_num;
    is_chosen = false;

    border.setPosition(x, y);
    border.setFillColor(sf::Color::Black);
    border.setSize(sf::Vector2f (size_x, size_y));

    chosen.setPosition(x+2, y+7);
    chosen.setSize(sf::Vector2f (3, 11));
    chosen.setFillColor(sf::Color::Blue);

    cell.setPosition(x+2, y+2);
    cell.setFillColor(global::floor);
    cell.setSize(sf::Vector2f (size_x-4, size_y-4));

    draw_cell_num.setFont(global::font);
    draw_cell_num.setPosition(x+2, y+2);
    draw_cell_num.setFillColor(sf::Color::White);
    draw_cell_num.setCharacterSize(25);
    draw_cell_num.setScale(0.2, 0.2);
    draw_cell_num.setString(cell_num);
}

void WeaponCells::draw(sf::RenderWindow &w) {
    w.draw(border);
    w.draw(cell);
    w.draw(draw_cell_num);
    if(weapon_picked) w.draw(weapon_inside);
    if(is_chosen)w.draw(chosen);
}

void WeaponCells::set_weapon_inside(sf::Sprite &w_i) {
    weapon_picked = true;
    weapon_inside = w_i;
    weapon_inside.setPosition(x+15,y+15);
    weapon_inside.setOrigin(5, 25);
    weapon_inside.setScale(0.3, 0.3);
}
void WeaponCells::move(float x, float y){
    border.setPosition(x, y);
    cell.setPosition(x+2, y+2);
    draw_cell_num.setPosition(x+2, y+2);
    if(weapon_picked) weapon_inside.setPosition(x+10,y+10);
    chosen.setPosition(x+2, y+7);
    this->x=x;
    this->y=y;
}


WeaponCells::WeaponCells() {}

WeaponCells::~WeaponCells() {}
