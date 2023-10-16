#include <SFML/Graphics.hpp>
#include <iostream>


int main(){
	//open the winow
    sf::RenderWindow window(sf::VideoMode(950, 650), "SFML works!");
	window.setFramerateLimit(60);
	
	
	//            we're making shapes and movables here


//PLAYER
	sf::CircleShape player(50.f); //shape created
	
	sf::Vector2f playerPosition(450,300); //'variable' for position, since it's subject to change
	
	player.setPosition((playerPosition)); //position
	
	player.setFillColor(sf::Color(217, 37, 73)); //red


	
	
//ENEMY(cirlce)
	sf::CircleShape enemy(30.f);  //shape created
	
	sf::Vector2f enemyPosition(70,70);
	enemy.setPosition((enemyPosition));
	
	
	enemy.setFillColor(sf::Color(64, 173, 47)); //green
	
	
	
	
	//variables velocity so character move
	
	float playerVX = 2;
	float playerVY = 2;
	
	float enemyVX = 3;
	float enemyVY = 3;
	
	
	
	//game loop?
	while (window.isOpen()){
		sf:: Event event;
		//keep the window open unless exit or something
		while(window.pollEvent(event)){ 
			if (event.type == sf::Event::Closed) window.close();
			
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
		}
		
		//collision with the void                                              this actually worked
		if (playerPosition.x < 0 || playerPosition.x > 850) playerVX *= -1, player.setFillColor(sf::Color(255, 255, 255));
		if (playerPosition.y < 0 || playerPosition.y > 550) playerVY *= -1, player.setFillColor(sf::Color(217, 37, 73));

		if (enemyPosition.x < 0 || enemyPosition.x > 890) enemyVX *= -1;
		if (enemyPosition.y < 0 || enemyPosition.y > 590) enemyVY *= -1;
		
		
		//idk
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
			player.setFillColor(sf::Color(147, 234, 118));
		}
		

		
		
		//PHYSICS
		
		playerPosition.x += playerVX;
		playerPosition.y += playerVY;
		
		player.setPosition((playerPosition));
		
		//enemy physics
		enemyPosition.x += enemyVX;
		enemyPosition.y += enemyVY;
		
		enemy.setPosition((enemyPosition));	
		
		
		
		
		
		//render, and certain order
	
		window.clear();
	
		window.draw(player);
		
		window.draw(enemy);
	
		window.display();
		
		
			
	}




    return 0;
}
