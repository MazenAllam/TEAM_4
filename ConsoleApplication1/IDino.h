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

class IDino {
private:
	int life ;
	int bullets = 0;
	bool ishit;
	bool ishit1;
	bool ishit2;
public:
	Vector2f velocity;
	Texture t;
	Sprite d;
	bool isSelected = false;
	IDino(string s, double x, double y);
	IDino();
	bool isHoveredOver(int, int);
	void update(float);
	void jump(Event);
	bool candoublejump;
	Texture dinodown;
	bool reset;
	SoundBuffer dinojumpBuffer;
	Sound dinojumpSound;
	SoundBuffer dinoducksBuffer;
	Sound dinoducksSound;
	bool is_collision(RectangleShape shape);
	bool is_collision1(RectangleShape shape);
	int get_life();

};