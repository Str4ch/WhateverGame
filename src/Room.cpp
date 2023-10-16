//
//  Room.cpp
//  WG
//
//  Created by Алексей Шмаков on 09.10.2023.
//

#include "Room.hpp"
#include "Player.hpp"
#include <iostream>
Room::Room(){}
Room::Room(std::vector <std::vector <int>> dr, int sx, int sy, int tp){
    door = dr;
    sizeX = sx;
    sizeY = sy;
    type = tp;
}
Room::~Room(){}

void Room::drawRoom(sf::RenderWindow &w){
    
    sf::Texture corner_texture,wall_texture,floor_texture,door_texture;
    corner_texture.loadFromFile("/Users/alekseyshmakov/WhateverGame/src/sprites/corner.png");
    
    wall_texture.loadFromFile("/Users/alekseyshmakov/WhateverGame/src/sprites/wall.png");
    floor_texture.loadFromFile("/Users/alekseyshmakov/WhateverGame/src/sprites/floor.png");
    door_texture.loadFromFile("/Users/alekseyshmakov/WhateverGame/src/sprites/door.png");
    
    wall_texture.setRepeated(true);
    floor_texture.setRepeated(true);
    door_texture.setRepeated(true);
    
    sf::Sprite floorsh;
    floorsh.setPosition(global::resolution.width/2-sizeX/2, int(global::resolution.height)/2-sizeY/2);
    floorsh.setTexture(floor_texture);
    floorsh.setTextureRect(sf::IntRect(0,0,sizeX,sizeY));
    w.draw(floorsh);
    
    //LEFT
    sf::Sprite wall;
    //std::cout<<" "<<global::resolution.height/2-sizeY/2;
    wall.setPosition(global::resolution.width/2-sizeX/2-50, global::resolution.height/2+sizeY/2);
    wall.setTexture(wall_texture);
    wall.setTextureRect(sf::IntRect(0,0,sizeY,50));
    //
    wall.rotate(270);
    w.draw(wall);
    //RIGHT
    wall.rotate(180);
    wall.setPosition(global::resolution.width/2+sizeX/2+50, int(global::resolution.height/2)-sizeY/2);
    w.draw(wall);
    //TOP
    wall.setTextureRect(sf::IntRect(0,0,sizeX,50));
    wall.rotate(270);
    wall.setPosition(global::resolution.width/2-sizeX/2, int(global::resolution.height/2)-sizeY/2-50);
    //wall.setSize(sf::Vector2f(sizeX,50));
    w.draw(wall);
    //BOTTOM
    wall.rotate(180);
    wall.setPosition(global::resolution.width/2+sizeX/2, global::resolution.height/2+sizeY/2+50);
    w.draw(wall);
    
    sf::Sprite corner;
    //corner.setSize(sf::Vector2f(50,50));
    
    //corner.setFillColor(global::corner);
    corner.setTexture(corner_texture);
    corner.setTextureRect(sf::IntRect(0, 0, 50, 50));
    corner.setTexture(corner_texture);
    //L_T
    corner.rotate(270);
    corner.setPosition(global::resolution.width/2-sizeX/2-50, int(global::resolution.height/2)-sizeY/2);
    w.draw(corner);
    
    //L_B
    corner.rotate(270);
    corner.setPosition(global::resolution.width/2-sizeX/2, global::resolution.height/2+sizeY/2+50);
    w.draw(corner);
    
    //R_T
    corner.rotate(180);
    corner.setPosition(global::resolution.width/2+sizeX/2, int(global::resolution.height/2)-sizeY/2-50);
    w.draw(corner);
    
    //R_B
    corner.rotate(90);
    corner.setPosition(global::resolution.width/2+sizeX/2+50, global::resolution.height/2+sizeY/2);
    w.draw(corner);
    
    sf::Sprite doorsh;
    doorsh.setTexture(door_texture);
    doorsh.setTextureRect(sf::IntRect(0,0,100,50));
    for(int i = 0;i<door.size();i++){
        if(door[i][0] == 0){
            doorsh.setRotation(270);
            doorsh.setPosition(global::resolution.width/2-sizeX/2-50, int(global::resolution.height/2)-sizeY/2+door[i][1]+100);
        }
        else if(door[i][0] == 1){
            //doorsh.setRotation(270);
            doorsh.setPosition(global::resolution.width/2-sizeX/2+door[i][1], int(global::resolution.height/2)-sizeY/2-50);
        }
        else if(door[i][0] == 2){
            doorsh.setRotation(90);
            doorsh.setPosition(global::resolution.width/2+sizeX/2+50, int(global::resolution.height/2)-sizeY/2+door[i][1]);
            //doorsh.rotate(270);
        }
        else{
            doorsh.setRotation(180);
            doorsh.setPosition(global::resolution.width/2-sizeX/2+door[i][1]+100, global::resolution.height/2+sizeY/2+50);
            doorsh.rotate(180);
        }
        w.draw(doorsh);
    }
}


int Room::nearRoom(int x, int y){
    //std::cout<<global::resolution.width/2-sizeX/2+door[0][1]<<" "<<global::resolution.height/2-sizeY/2<<'\n';
    for(int i = 0;i<door.size();i++){
        if(door[i][0] == 0){
            if(x>(global::resolution.width/2-sizeX/2) && x<(global::resolution.width/2-sizeX/2+50) && y>(int(global::resolution.height/2)-sizeY/2+door[i][1]) && y<(int(global::resolution.height/2)-sizeY/2+door[i][1]+300)){
                return door[i][2];
            }
        }
        else if(door[i][0] == 1){
            if(x>global::resolution.width/2-sizeX/2+door[i][1] && x<global::resolution.width/2-sizeX/2+door[i][1]+300 && y>int(global::resolution.height/2)-sizeY/2 && y<int(global::resolution.height/2)-sizeY/2+50){
                return door[i][2];
            }
        }
        else if(door[i][0] == 2){
            
            if(x>(global::resolution.width/2+sizeX/2-50) && x<(global::resolution.width/2+sizeX/2) && y>global::resolution.height/2-sizeY/2+door[i][1] && y<int(global::resolution.height/2)-sizeY/2+door[i][1] +300){
                return door[i][2];
            }
        }
        else{
            if(x>global::resolution.width/2-sizeX/2+door[i][1] && x<global::resolution.width/2-sizeX/2+door[i][1]+300 && y>global::resolution.height/2+sizeY/2-50 && y<global::resolution.height/2+sizeY/2){
                return door[i][2];
            }
        }
    }
    return -1;
}
