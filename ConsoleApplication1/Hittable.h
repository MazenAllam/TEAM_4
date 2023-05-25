#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <random>
using namespace sf;
using namespace std;

//class Hittable
//{
//		Texture t;
//		Sprite H; 
//		int randomNumber{ 0 };
//public:
//	Hittable(string ss, int posx, int posy, float scalex, float scaley);
//	Sprite getsprite();
//
//
//};
class Hittable
{
private:
	Vector2u imageCount;
	Vector2u currentImage;
	float totalTime;
	float switchTime;


public:
	Hittable(Texture* texture, Vector2u imageCount, float switchTime);
	~Hittable();
	void Update(int row, float deltaTime);
	IntRect uvRect;
	//bool is_collision(RectangleShape shape);
};



