#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "menu.h"
#include "IDino.h"
#include "Dino.h"
#include "MainMenu.h"
#include "Background.h"
#include "Backgroundn.h"
#include "Hittable.h"
#include <fstream>
using namespace sf;
using namespace std;


class Game {
	int x ;
	time_t givemetime;
	time_t givemetime4;
	int score = 0;
	int scroll = 0;
	int scroll1 = 0;
	int scroll2 = 0;
	string state;
	Sprite backgound;
	string Difficulty;
	IDino dinoGame;
	int speed;
	int live=3;
	Sprite enemyyyy1;
public:
	void run();
	Game();
	void processEvents(Event event, Background& back1, Background& back2, Background& back3, Background& back4, Sound& backgroundsound, MainMenu& button1, MainMenu& button2, MainMenu& button3, MainMenu& button4, MainMenu& buttonE, MainMenu& buttonH, bool& ismuted, IDino& dino, IDino& dinoII);
	void Update();
	void Render(float& deltaTime, bool& thirdmusic, Sound& gameplaySound, Background& generalbackground, MainMenu& button1, MainMenu& button2, MainMenu& button3, MainMenu& button4, MainMenu& buttonE, MainMenu& buttonH, Background& back1, Background& back2, Background& back3, Background& back4, bool& firstMusic, Sound& backgroundsound, Dino& dino1Player, Dino& dino2Player, Dino& dino3Player, RectangleShape& dino1, RectangleShape& dino2, RectangleShape& dino3, Backgroundn& rect1, Backgroundn& rect2, Backgroundn& rect3, IDino& dino, Text&, IDino& dinoII, Sprite createdbutton, Hittable& Hittable1Enemy, RectangleShape& enemy1, RectangleShape& enemy2, Hittable& Hittable2Enemy, RectangleShape& treasure1, Hittable& Hittable1Treasure, RectangleShape& treasure2, Hittable& hittable2Treasure, RectangleShape& heart1, Hittable& hittable1Heart, Text& elapsed1text, RectangleShape& bullet1, Hittable& hittable1bullet);
};