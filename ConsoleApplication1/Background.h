#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "menu.h"
#include "IDino.h"
#include "MainMenu.h"
using namespace sf;
using namespace std;


class Background {
	Texture t;
	Sprite s;
public:
	Background(string ss, int posx, int posy, float scalex, float scaley);
	Sprite getsprite();
	bool ishoveredover(int x, int y);
	Texture get_Size();

};