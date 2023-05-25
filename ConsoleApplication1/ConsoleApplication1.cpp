#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "menu.h"
#include "IDino.h"
#include "MainMenu.h"
#include "Game.h"
using namespace sf;
using namespace std;




int main()
{
	Game mygame;
	mygame.run();
	
}

