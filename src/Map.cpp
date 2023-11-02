#include "Map.hpp"

Map::Map(){
    rm_count = std::rand()%7+6;
    
    std::vector<std::vector < std::vector <int> >> door;//doors for different rooms
    for(int i = 0;i<rm_count;i++){
        door.push_back(std::vector <std::vector<int>>());
    }
    
    room = new Room[rm_count];
    
    int door_count = (rm_count-1)*2;
    
    
    int door_pos;//door position on the wall
    int door_place;//door wall
    int which_room = 1;
    
    std::vector<int> mem(4);//massive that stores on which walls there are doors
    std::vector<int> onedoor(3);//
    
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
            
            //on which wall door would be
            do{
                door_place = rand()%4;
                
            }while(!check(mem, door_place));
            
            mem[i] = door_place;//not to be dublicated
            
            door_pos = rand()%2*50;//position on the wall
            
            onedoor[0] = door_place;
            onedoor[1] = door_pos;
            onedoor[2] = which_room;
            
            door[k].push_back(onedoor);
            
            //the same door but in the other room
            onedoor[2] = k;
            switch (door_place) {
                case 0:
                    onedoor[0] = 2;
                    break;
                case 1:
                    onedoor[0] = 3;
                    break;
                case 2:
                    onedoor[0] = 0;
                    break;
                case 3:
                    onedoor[0] = 1;
                    break;
            }
            door[which_room].push_back(onedoor);
            
            which_room++;
        }
        
        door_count-=in_this_room_doors*2;
    }
    int sx,sy;//sizes
    for(int i = 0;i<rm_count;i++){
        sx = rand()%7*100+300;
        sy = rand()%7*100+300;
        room[i] = Room(door[i],sx,sy,rand()%4);
    }
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
