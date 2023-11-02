#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <cmath>
#include <chrono>
#include <unistd.h>

#include "Player.hpp"
#include "Map.hpp"
#include "globalvariables.hpp"

int main()
{
    
    sf::RenderWindow window(global::resolution, "Whatever Game");
    std::cout<<"smth";
    sf::View view(sf::FloatRect(0, 0,global::resolution.width/4, global::resolution.height/4));
    view.setCenter(global::resolution.width/2,global::resolution.height/2);
    
    Player my_player(global::resolution.width/2,global::resolution.height/2,100,0.1,10,25);
    
    sf::Vector2f direction;
    float length;
    
    set_evrth();
    
   bool W = false,
        A = false,
        S = false,
        D = false,
        Shift = false;

    Map map;
    bool f = true;//var that helps switching the doors
    
    int room_pos = 0;
    
    std::chrono::time_point tick = std::chrono::steady_clock::now();
    std::chrono::time_point tack = std::chrono::steady_clock::now();
    std::chrono::duration<float> deltatime;
    
    //window.setFramerateLimit(480);
    while (window.isOpen())
    {
        tick = std::chrono::steady_clock::now();
        //usleep(12500);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            
            W = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
            A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
            D = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
            S = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
            Shift = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
            
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
                map.room[room_pos].chest.open(my_player);
                if(!map.room[room_pos].chest.weapon_is_picked)my_player.player_weapons[0] = map.room[room_pos].chest.pick(my_player);
            }
            else f = true;
            
            
            //std::cout<<event.key.code;
        }
        if(Shift){
            //my_player.speed = 0.15;
        }
        else{
            //my_player.speed = 0.1;
        }
        length = std::pow((D-A)*(D-A)+(S-W)*(S-W), 0.5);

        //std::cout<<(angle);
        tack = std::chrono::steady_clock::now();
        deltatime = (std::chrono::duration<float>(tack-tick));
        direction.x = my_player.speed*(D - A) * (deltatime.count()*10000.f);
        direction.y = my_player.speed*(S-W) * (deltatime.count()*10000.f);
        
        if(length!=0){
            direction.x*=std::abs((D-A)/length);
            direction.y*=std::abs((S-W)/length);
        }
        my_player.move(direction.x,direction.y);
        view.move(direction.x,direction.y);
        
        
        //std::cout<<my_player.hitpoints<<std::endl;
        window.clear();
        window.setView(view);
        map.drawMap(window,room_pos,my_player);
        my_player.draw(window);
        window.display();
    }

    return 0;
}
