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
    //door = dr;
    door_count = int(dr.size());
    doors = new Door[door_count];
    for(int i = 0;i<door_count;i++){
        switch (dr[i][0]) {
            case 0:
                doors[i] = Door(float(global::resolution.width/2-sx/2-50), float(global::resolution.height/2-sy/2+dr[i][1]+100), dr[i][2],0);
                break;
            case 1:
                doors[i] = Door(float(float(global::resolution.width/2)-sx/2+dr[i][1]), float(float(global::resolution.height/2)-sy/2-50),dr[i][2],1);
                break;
            case 2:
                doors[i] = Door(float(global::resolution.width/2)+sx/2+50, float(global::resolution.height/2)-sy/2+dr[i][1],dr[i][2],2);
                break;
            case 3:
                doors[i] = Door(float(global::resolution.width/2-sx/2+dr[i][1]+100), float(global::resolution.height/2+sy/2+50),dr[i][2],3);
                break;
        }
    }
    sizeX = sx;
    sizeY = sy;
    type = tp;
    
    
    
    
    
    
    floorsh.setPosition(float(global::resolution.width/2)-sizeX/2, float(global::resolution.height)/2-sizeY/2);
    floorsh.setTexture(global::floor_texture);
    floorsh.setTextureRect(sf::IntRect(0,0,sizeX,sizeY));
    
    wall.setTexture(global::wall_texture);
    
    corner.setTexture(global::corner_texture);
    corner.setTextureRect(sf::IntRect(0, 0, 50, 50));
}
Room::~Room(){}

void Room::drawRoom(sf::RenderWindow &w){
    
    w.draw(floorsh);
    
    //LEFT
    wall.setTextureRect(sf::IntRect(0,0,sizeY,50));
    wall.setPosition(float(global::resolution.width/2)-sizeX/2-50, float(global::resolution.height/2)+sizeY/2);
    wall.setRotation(270);
    w.draw(wall);
    
    //TOP
    wall.setTextureRect(sf::IntRect(0,0,sizeX,50));
    wall.rotate(90);
    wall.setPosition(float(global::resolution.width/2)-sizeX/2, float(global::resolution.height/2)-sizeY/2-50);
    w.draw(wall);
    
    //RIGHT
    wall.setTextureRect(sf::IntRect(0,0,sizeY,50));
    wall.rotate(90);
    wall.setPosition(float(global::resolution.width/2)+sizeX/2+50, float(global::resolution.height/2)-sizeY/2);
    w.draw(wall);
    
    
    
    //BOTTOM
    wall.setTextureRect(sf::IntRect(0,0,sizeX,50));
    wall.rotate(90);
    wall.setPosition(float(global::resolution.width/2)+sizeX/2, float(global::resolution.height/2)+sizeY/2+50);
    w.draw(wall);
    
    //L_T
    corner.setRotation(270);
    corner.setPosition(global::resolution.width/2-sizeX/2-50, int(global::resolution.height/2)-sizeY/2);
    w.draw(corner);
    
    //R_T
    
    corner.rotate(90);
    corner.setPosition(global::resolution.width/2+sizeX/2, int(global::resolution.height/2)-sizeY/2-50);
    w.draw(corner);
    
    //R_B
    corner.rotate(90);
    corner.setPosition(global::resolution.width/2+sizeX/2+50, global::resolution.height/2+sizeY/2);
    w.draw(corner);
    
    //L_B
    corner.rotate(90);
    corner.setPosition(global::resolution.width/2-sizeX/2, global::resolution.height/2+sizeY/2+50);
    w.draw(corner);
    
    
    //
    
    
    
    
    
    for(int i = 0;i<door_count;i++){
        doors[i].draw_door(w);
    }
}


int Room::nearRoom(Player &p){
    for(int i = 0;i<door_count;i++){
        if(doors[i].next_to_room(p)){
            p.x = doors[i].x;
            p.y = doors[i].y;
            //p.player_shape.setPosition(doors[i].x, doors[i].y);
            return doors[i].room_tp;
        }
    }
    return -1;
}
