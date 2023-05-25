#pragma once
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 4 //play, about,credits, exit
class menu
{
private: 
	sf::Font font;
	sf::Text text();

public: 
	menu(float width, float height);

	void draw(sf::RenderWindow& window);
	void Moveup();
	void Movedown();
	void setFillColor();
	int GetPressedoption();
		
};

