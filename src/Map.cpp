//
//  Map.cpp
//  WG
//
//  Created by Алексей Шмаков on 09.10.2023.
//

#include "Map.hpp"
#include "globalvariables.hpp"

#include <random>
#include <iostream>

Map::Map(){
    //std::cout<<1;
    rm_count = std::rand()%7+6;
    
    //rm_count = 2;
    std::vector<std::vector < std::vector <int> >> door;// = {{{2,100}},{{0,100}}};
    for(int i = 0;i<rm_count;i++){
        door.push_back(std::vector <std::vector<int>>());
    }
    
    room = new Room[rm_count];
    
    int door_count = rand()%3+1;
    
    door_count = (rm_count-1)*2;
    
    int door_pos;
    int door_place;
    int which_room = 1;
    
    std::vector<int> mem(4);
    std::vector<int> onedoor(3);
    
    //mem.push_back(door_place);
    for(int k = 0;k<rm_count;k++){
        int in_this_room_doors = rand()%3+1;
        mem[0] = -1;
        mem[1] = -1;
        mem[2] = -1;
        mem[3] = -1;
        if(in_this_room_doors>door_count/2){
            in_this_room_doors = door_count/2;
        }
        for(int i = 0;i<in_this_room_doors ;i++){
            
            //на какой стене будет дверь
            do{
                door_place = rand()%4;
                
            }while(!check(mem, door_place));
            
            mem[i] = door_place;//чтобы не повторялись
            
            door_pos = rand()%2*50;//позиция на стене
            
            onedoor[0] = door_place;
            onedoor[1] = door_pos;
            onedoor[2] = which_room;
            
            door[k].push_back(onedoor);
            //проход в эту же дверь с другой комнаты
            
            onedoor[2] = k;
            if(door_place == 0){
                onedoor[0] = 2;
                door[which_room].push_back(onedoor);
            }
            else if (door_place == 1){
                onedoor[0] = 3;
                door[which_room].push_back(onedoor);
            }
            else if (door_place == 2){
                onedoor[0] = 0;
                door[which_room].push_back(onedoor);
            }
            else{
                onedoor[0] = 1;
                door[which_room].push_back(onedoor);
            }
            which_room++;
        }
        
        door_count-=in_this_room_doors*2;
    }
    //TODO Сделать генерацию карту методом комната -> двери -> комнаты
    int sx,sy;
    for(int i = 0;i<rm_count;i++){
        sx = rand()%7*100+300;
        sy = rand()%7*100+300;
        room[i] = Room(door[i],sx,sy,rand()%4);
    }
    //room[0] = Room(door[0],1000,600,0);
    //room[1] = Room(door[1],300,300,0);
}
Map::~Map(){}

void Map::drawMap(sf::RenderWindow &w, int player_pos, Player& m_p){
    room[player_pos].drawRoom(w,m_p);
}
bool Map::check(std::vector<int> m, int dp){
    for(int i = 0;i<4;i++){
        if(m[i]==dp){
            return false;
        }
    }
    return true;
}
