#ifndef Door_hpp
#define Door_hpp

#include "SFML/Graphics.hpp"

#include "Player.hpp"
#include "globalvariables.hpp"

class Door{
public:
    sf::Sprite door_sp;
    sf::Texture door_texture;
    sf::RectangleShape enter_the_door;
    float x;
    float y;
    int wall_num;
    int room_tp;
    
    Door();
    Door(float x, float y, int room_tp,int wall_num);
    ~Door();
    
    bool next_to_room(Player &p);
    void draw_door(sf::RenderWindow &w);
    
};

#endif /* Door_hpp */
