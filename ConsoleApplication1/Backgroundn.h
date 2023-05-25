#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf;
using namespace std;

class Backgroundn
{

private:
	RectangleShape rect1;
	Font font;
	Text text;
public:
	Backgroundn();
	~Backgroundn();
	void update(float dt);
	void draw(RenderWindow& window);
	void displayText(RenderWindow& window);
	void setPose(float x, float y);
	void setRectColor(int x, int y, int z);




};

