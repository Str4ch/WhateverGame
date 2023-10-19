#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>

#include "Player.hpp"
#include "Map.hpp"
#include "globalvariables.hpp"

int main()
{
    
    sf::RenderWindow window(global::resolution, "Whatever Game");
    
    sf::View view(sf::FloatRect(0, 0,global::resolution.width/4, global::resolution.height/4));
    view.setCenter(global::resolution.width/2,global::resolution.height/2);
    window.setView(view);
    
    Player my_player(global::resolution.width/2,global::resolution.height/2,100,0.1,0,10,25);
    my_player.prnt();
    //window.setFramerateLimit(240);
    
    sf::Vector2f direction;
    float angle;
    
   bool W = false,
        A = false,
        S = false,
        D = false;

    Map map;
    bool f = true;
    //std::cout<<map.rm_count;
    
    int room_pos = 0;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            
            W = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
            A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
            D = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
            S = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && f){
                f = false;
                int prev_room = room_pos;
                if(map.room[room_pos].nearRoom(my_player)!=-1){
                    int prev_room = room_pos;
                    
                    room_pos = map.room[room_pos].nearRoom(my_player);
                    
                    for(int k = 0;k<map.room[room_pos].door_count;k++){
                        if((prev_room==map.room[room_pos].doors[k].room_tp)){
                            my_player.x = map.room[room_pos].doors[k].enter_the_door.getPosition().x+7.5;
                            my_player.y = map.room[room_pos].doors[k].enter_the_door.getPosition().y+12.5;
                            my_player.player_shape.setPosition(my_player.x, my_player.y);
                            view.setCenter(my_player.x, my_player.y);
                        }
                    }
                }
            }
            else f = true;
            //std::cout<<event.key.code;
        }
        
        angle = atan((D-A)/(S-W))+M_PI_2;
        
        if(D-A==0){
            angle = M_PI_2;
        }
        else if(S-W==0){
            angle = 0;
        }
        //std::cout<<(angle);
        
        direction.x = my_player.speed*(D - A);//*(cos(angle));
        direction.y = my_player.speed*(S-W);//*(sin(angle));
        my_player.move(direction.x,direction.y);
        view.move(direction.x,direction.y);
        
        window.clear();
        window.setView(view);
        map.drawMap(window,room_pos);
        my_player.draw(window);
        window.display();
    }

    return 0;
}
