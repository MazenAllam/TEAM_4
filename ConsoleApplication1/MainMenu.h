#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf;
using namespace std;
#include <cmath>

class MainMenu
{
private:
	
	RectangleShape buttonshape;
	Font font;
	Text text;
	
public:
	MainMenu(int textpx, int textpy, int buttonpx, int buttonpy, string textt);
	
	//functions
	bool isselected = false;
	void selected();
	void unselected();
	void drawbutton(RenderWindow w);
	void selectandunselect();
	RectangleShape getshape();
	Text getText();
	bool getselection();


};