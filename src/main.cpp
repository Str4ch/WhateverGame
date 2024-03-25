#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <cmath>
#include <chrono>

#include "Player.hpp"
#include "Map.hpp"
#include "globalvariables.hpp"

int main()
{
    sf::RenderWindow window(global::resolution, "Whatever Game");
    
    sf::View view(sf::FloatRect(0, 0,global::resolution.width/4, global::resolution.height/4));
    view.setCenter(global::resolution.width/2,global::resolution.height/2);
    
    Player my_player(global::resolution.width/2,global::resolution.height/2,100,0.1,20,25);

    sf::Vector2f direction;
    
    float length;//var to correct the speed(the same speed, not depending on the direction)
    
    set_evrth();//sets global vars and textures
    
    bool W = false,
        A = false,
        S = false,
        D = false,
        Shift = false;

    Map map;
    
    bool f = true;//var that helps switching the doors
    
    int room_pos = 0;//current position of player
    
    std::chrono::time_point tick = std::chrono::steady_clock::now();
    std::chrono::time_point tack = std::chrono::steady_clock::now();
    std::chrono::duration<float> deltatime;//if fps drops this var helps to correct the movement
    std::chrono::time_point attack_start = std::chrono::steady_clock::now();
    std::chrono::time_point attack_end = std::chrono::steady_clock::now();

    int dir_x;
    int dir_y;
    while (window.isOpen())
    {
        tick = std::chrono::steady_clock::now();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            
            W = sf::Keyboard::isKeyPressed(sf::Keyboard::W);//
            A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);//
            S = sf::Keyboard::isKeyPressed(sf::Keyboard::S);//
            D = sf::Keyboard::isKeyPressed(sf::Keyboard::D);//vars used to move player
            Shift = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);//

            switch (event.key.code) {
                case sf::Keyboard::E:
                    if (f) {
                        f = false;
                        int prev_room = room_pos;
                        if (map.room[room_pos].nearRoom(my_player) != -1) {//change the room by entering the door
                            int prev_room = room_pos;

                            room_pos = map.room[room_pos].nearRoom(my_player);

                            for (int k = 0; k < map.room[room_pos].door_count; k++) {
                                if (prev_room == map.room[room_pos].doors[k].room_tp) {
                                    my_player.x = map.room[room_pos].doors[k].enter_the_door.getPosition().x + 7.5;
                                    my_player.y = map.room[room_pos].doors[k].enter_the_door.getPosition().y + 12.5;
                                    my_player.player_shape.setPosition(my_player.x, my_player.y);
                                    view.setCenter(my_player.x, my_player.y);
                                }
                            }
                            break;
                        }
                        map.room[room_pos].chest.open(my_player);//open the chest
                        if (!map.room[room_pos].chest.weapon_is_picked) {
                            my_player.pl_weapons[my_player.weapon_rn] = map.room[room_pos].chest.pick(my_player);
                            if ((my_player.pl_weapons[my_player.weapon_rn].first) != 0) {
                                my_player.weapon_cells[my_player.weapon_rn].set_weapon_inside(
                                        (static_cast<Weapon *>(my_player.pl_weapons[my_player.weapon_rn].second)->weapon_sp));
                                (static_cast<Weapon *>(my_player.pl_weapons[my_player.weapon_rn].second)->x = my_player.x);
                                (static_cast<Weapon *>(my_player.pl_weapons[my_player.weapon_rn].second)->y = my_player.y);
                            }
                        }
                    } else f = true;
                    break;
                case sf::Keyboard::F:
                    if (!my_player.is_atacking) {
                        my_player.is_atacking = true;
                        attack_start = std::chrono::steady_clock::now();
                    }
                    break;
                case sf::Keyboard::Num1 :
                    my_player.weapon_cells[my_player.weapon_rn].is_chosen = false;
                    my_player.weapon_rn = 0;
                    my_player.weapon_cells[my_player.weapon_rn].is_chosen = true;
                    break;
                case sf::Keyboard::Num2 :
                    my_player.weapon_cells[my_player.weapon_rn].is_chosen = false;
                    my_player.weapon_rn = 1;
                    my_player.weapon_cells[my_player.weapon_rn].is_chosen = true;
                    break;
                case sf::Keyboard::Num3 :
                    my_player.weapon_cells[my_player.weapon_rn].is_chosen = false;
                    my_player.weapon_rn = 2;
                    my_player.weapon_cells[my_player.weapon_rn].is_chosen = true;
                    break;
                case sf::Keyboard::Num4 :
                    my_player.weapon_cells[my_player.weapon_rn].is_chosen = false;
                    my_player.weapon_rn = 3;
                    my_player.weapon_cells[my_player.weapon_rn].is_chosen = true;
                    break;
            }
        }

        if(my_player.is_atacking){
            attack_end = std::chrono::steady_clock::now();
            std::chrono::duration<float> attack_duration = std::chrono::duration<float>(attack_end - attack_start);
            if(attack_duration.count() > 1.5){
                my_player.is_atacking = false;
            }
        }

        if(Shift){
            my_player.speed = 0.15;
        }
        else{
            my_player.speed = 0.1;
        }
        dir_x = (D-A);
        dir_y = (S-W);
        
        length = std::pow(dir_x*dir_x+dir_y*dir_y, 0.5);

        tack = std::chrono::steady_clock::now();
        deltatime = (std::chrono::duration<float>(tack-tick));
        direction.x = my_player.speed*(D - A) * (deltatime.count()*10000.f);
        direction.y = my_player.speed*(S-W) * (deltatime.count()*10000.f);
        if (length != 0) {
            direction.x *= std::abs(dir_x / length);
            direction.y *= std::abs(dir_y / length);

            if (my_player.x > map.room[room_pos].floorsh.getPosition().x + map.room[room_pos].sizeX - my_player.player_shape.getSize().x/2) 
                direction.x = my_player.speed * (-A) * (deltatime.count() * 10000.f);
            if (my_player.x < map.room[room_pos].floorsh.getPosition().x + my_player.player_shape.getSize().x/2)                           
                direction.x = my_player.speed * D * (deltatime.count() * 10000.f);                   
            if (my_player.y < map.room[room_pos].floorsh.getPosition().y + my_player.player_shape.getSize().y/2)
                direction.y = my_player.speed * S * (deltatime.count() * 10000.f);                  
            if (my_player.y > map.room[room_pos].floorsh.getPosition().y + map.room[room_pos].sizeY - my_player.player_shape.getSize().y/2)
                direction.y = my_player.speed * (-W) * (deltatime.count() * 10000.f);
            
            my_player.move(direction.x, direction.y, dir_x, dir_y);
            view.move(direction.x, direction.y);
        }
        window.clear();
        window.setView(view);
        
        map.drawMap(window,room_pos,my_player);
        my_player.draw(window);
        window.display();
        //draws smth
    }

    return 0;
}
