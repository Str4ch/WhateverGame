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

class Room{
public:
    
    std::vector <std::vector <int>> door;//массив в котором хранится кол-во дверей их позиция и на какой стене
    
    //размеры
    int sizeX;
    int sizeY;
    
    //тип
    int type;
    
    
    void drawRoom(sf::RenderWindow &w);
    int nearRoom(int x, int y);
    
    Room();
    Room(std::vector <std::vector <int>> dr, int sx, int sy, int tp);
    ~Room();
};
#endif /* Room_hpp */
