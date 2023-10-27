//
//  Room.hpp
//  WG
//
//  Created by Алексей Шмаков on 09.10.2023.
//

#ifndef Room_hpp
#define Room_hpp

#include<vector>

#include "SFML/Graphics.hpp"
#include "globalvariables.hpp"
#include "Player.hpp"
#include "Door.hpp"
#include "Enemy.hpp"

class Room{
public:
    
    //std::vector <std::vector <int>> door;//массив в котором хранится кол-во дверей их позиция и на какой стене
    
    Door* doors;
    Enemy* enemies;
    
    int door_count,enemy_count;
    
    //размеры
    int sizeX;
    int sizeY;
    
    //тип
    int type;
    
    sf::Sprite floorsh,wall,corner;
    
    void drawRoom(sf::RenderWindow &w, Player& m_p);
    int nearRoom(Player &p);
    
    Room();
    Room(std::vector <std::vector <int>> dr, int sx, int sy, int tp);
    ~Room();
};
#endif /* Room_hpp */
