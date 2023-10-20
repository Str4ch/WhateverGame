//
//  Map.hpp
//  WG
//
//  Created by Алексей Шмаков on 09.10.2023.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Room.hpp"
#include "vector"

class Map{
    
    bool check(std::vector<int> m,int dp);
    int get_room_num(int x, int y);
public:
    Room *room;
    int rm_count;
    Map();
    void drawMap(sf::RenderWindow &w, int player_pos);
    ~Map();
};
#endif /* Map_hpp */
