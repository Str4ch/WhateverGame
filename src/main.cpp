#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>

#include "Player.hpp"
#include "Map.hpp"
#include "globalvariables.hpp"

int main()
{
    
    sf::RenderWindow window(global::resolution, "Whatever Game");
    
    sf::View view(sf::FloatRect(0,0,1280,720));//(sf::FloatRect(0, 0,global::resolution.width/4, global::resolution.height/4));
    view.setCenter(global::resolution.width/2,global::resolution.height/2);
    window.setView(view);
    
    Player my_player(global::resolution.width/2,global::resolution.height/2,100,1,0,10,25);
    my_player.prnt();
    //window.setFramerateLimit(240);
    
   // bool W,A,S,D;
    
    Map map;
    
    //std::cout<<map.rm_count;
    
    int room_pos = 0;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.key.code == sf::Keyboard::W) {
                my_player.move(0,-5);
                view.move(0, -5);
            }
            
            if(event.key.code == sf::Keyboard::A) {
                my_player.move(-5,0);
                view.move(-5, 0);
            }
            if(event.key.code == sf::Keyboard::D){
                my_player.move(5,0);
                view.move(5, 0);
            }
            if(event.key.code == sf::Keyboard::S) {
                my_player.move(0,5);
                view.move(0, 5);
            }
            if(event.key.code == sf::Keyboard::E){
                if(map.room[room_pos].nearRoom(my_player.x,my_player.y)!=-1){
                    room_pos = map.room[room_pos].nearRoom(my_player.x,my_player.y);
                }
            }
            //std::cout<<event.key.code;
        }
        
        
        
        window.clear();
        window.setView(view);
        map.drawMap(window,room_pos);
        my_player.draw(window);
        window.display();
    }

    return 0;
}
