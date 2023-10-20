//
//  Door.cpp
//  WG
//
//  Created by Алексей Шмаков on 18.10.2023.
//

#include "Door.hpp"
#include <iostream>

Door::Door(){}
Door::Door(float x, float y, int room_tp,int wall_num){
    this->x = x;
    this->y = y;
    this->room_tp = room_tp;
    this->wall_num = wall_num;
    door_sp.setPosition(x, y);
    door_sp.setTextureRect(sf::IntRect(0,0,100,50));
    
    switch (wall_num) {
        case 0:
            door_sp.setRotation(270);
            
            enter_the_door.setSize(sf::Vector2f(25,50));
            enter_the_door.setPosition(x+50, y-75);
            
            break;
        case 1:
            enter_the_door.setSize(sf::Vector2f(50,25));
            enter_the_door.setPosition(x+25, y+50);
            break;
        case 2:
            door_sp.setRotation(90);
            
            enter_the_door.setSize(sf::Vector2f(25,50));
            enter_the_door.setPosition(x-75, y+25);
            
            break;
        case 3:
            door_sp.setRotation(180);
            
            enter_the_door.setSize(sf::Vector2f(50,25));
            enter_the_door.setPosition(x-75, y-75);
            
            break;
    }
}

Door::~Door(){}
void Door::draw_door(sf::RenderWindow &w){
    sf::Texture door_texture;
    door_texture.loadFromFile("/Users/alekseyshmakov/WhateverGame/src/sprites/door.png");
    door_sp.setTexture(door_texture);
    
    enter_the_door.setFillColor(sf::Color(0,0,0,0));
    
    
    w.draw(door_sp);
    w.draw(enter_the_door);
}

bool Door::next_to_room(Player &p){
    return p.player_shape.getGlobalBounds().intersects(enter_the_door.getGlobalBounds());
}
