#ifndef Map_hpp
#define Map_hpp

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

#include "Room.hpp"
#include "Player.hpp"
#include "globalvariables.hpp"

class Map{
    bool check(std::vector<int> m,int dp);
    int get_room_num(int x, int y);
public:
    Room *room;
    int rm_count;
    Map();
    void drawMap(sf::RenderWindow &w, int player_pos, Player& m_p);
    ~Map();
};
#endif /* Map_hpp */
