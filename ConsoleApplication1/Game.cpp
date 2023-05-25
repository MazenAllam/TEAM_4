#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
//#include "Credits.h"
#include"Profile.h"
#include <iostream>
#include <ctime>
#include<cstdlib>
#include<ctime>
#include <chrono>
#include <thread>

using namespace std;
RenderWindow window(VideoMode(1200, 800), "SFML Works!");
void Game::run()
{

	window.setFramerateLimit(60); // to not burn out your graphics card
	IDino dino("DinoSprite.png", 100, 500);
	IDino dinoII("DinoSprite.png", 700, 500);
	// vectors
	Vector2f circle1pos = Vector2f(100.f, 100.f);

	// shapes and properties
	CircleShape circle1(100.f);
	circle1.setFillColor(Color::Green);
	circle1.setPosition(circle1pos);

	//jumping feature


	Texture tex;
	tex.loadFromFile("newproject.png");
	Sprite createdbutton;
	createdbutton.setTexture(tex);
	createdbutton.scale(.5, .5);
	createdbutton.setPosition(600, 500);



	Text timee;
	Font f;
	timee.setCharacterSize(20);
	timee.setPosition(900, 00);
	f.loadFromFile("Fonts/Minecraft.ttf");
	timee.setFont(f);
	//ctime() returns given time

	//nada
	Backgroundn rect1;
	Backgroundn rect2;
	Backgroundn rect3;

	RectangleShape dino1(Vector2f(200.f, 120.f));
	dino1.setPosition(300.f, 500.f);
	Texture dino1Texture;
	dino1Texture.loadFromFile("DinoSprites4.png");

	dino1.setTexture(&dino1Texture);
	Dino dino1Player(&dino1Texture, Vector2u(13, 1), 3.0f);

	RectangleShape dino2(Vector2f(200.f, 120.f));
	dino2.setPosition(500.f, 500.f);
	Texture dino2Texture;
	dino2Texture.loadFromFile("DinoSprites2.png");

	dino2.setTexture(&dino2Texture);
	Dino dino2Player(&dino2Texture, Vector2u(15, 1), 0.5f);

	RectangleShape dino3(Vector2f(200.f, 120.f));
	dino3.setPosition(700.f, 500.f);
	Texture dino3Texture;
	dino3Texture.loadFromFile("DinoSprites3.png");

	dino3.setTexture(&dino3Texture);
	Dino dino3Player(&dino3Texture, Vector2u(15, 1), 3.0f);
	float deltaTime = 0.0f;
	Clock clock;


	RectangleShape enemy1(Vector2f(100.f, 100.f));
	enemy1.setPosition(500.f, 660.f);
	Texture enemy1Texture;
	enemy1Texture.loadFromFile("Enemy1.png");

	enemy1.setTexture(&enemy1Texture);
	Hittable hittable1Enemy(&enemy1Texture, Vector2u(10, 1), 3.0f);

	RectangleShape enemy2(Vector2f(100.f, 100.f));
	enemy2.setPosition(500.f, 550.f);
	Texture enemy2Texture;
	enemy2Texture.loadFromFile("Enemy2.png");

	enemy2.setTexture(&enemy2Texture);
	Hittable hittable2Enemy(&enemy2Texture, Vector2u(13, 1), 3.0f);

	RectangleShape treasure1(Vector2f(75.f, 75.f));
	treasure1.setPosition(400.f, 550.f);
	Texture treasure1Texture;
	treasure1Texture.loadFromFile("Treasure.png");

	treasure1.setTexture(&treasure1Texture);
	Hittable hittable1Treasure(&treasure1Texture, Vector2u(1, 1), 3.0f);

	RectangleShape treasure2(Vector2f(75.f, 75.f));
	treasure2.setPosition(500.f, 550.f);
	Texture treasure2Texture;
	treasure2Texture.loadFromFile("Treasure2.png");

	treasure2.setTexture(&treasure2Texture);
	Hittable hittable2Treasure(&treasure2Texture, Vector2u(6, 1), 3.0f);


	RectangleShape heart1(Vector2f(100.f, 75.f));
	heart1.setPosition(500.f, 550.f);
	Texture heart1Texture;
	heart1Texture.loadFromFile("Hearts.png");

	heart1.setTexture(&heart1Texture);
	Hittable hittable1Heart(&heart1Texture, Vector2u(5, 1), 3.0f);

	RectangleShape bullet1(Vector2f(50.f, 50.f));
	bullet1.setPosition(500.f, 680.f);
	Texture bullet1Texture;
	bullet1Texture.loadFromFile("Bullet.png");

	bullet1.setTexture(&bullet1Texture);
	Hittable hittable1bullet(&bullet1Texture, Vector2u(1, 1), 3.0f);

	// Arrows Feature
   /* RectangleShape arrow(Vector2f(100.f, 100.f));
	arrow.setPosition(1200.f, 800.f);
	Texture arrowTexture;
	arrowTexture.loadFromFile("arrows.png");

	arrow.setTexture(&arrowTexture);
	Dino arrowPlayer(&arrowTexture, Vector2u(8, 1), 3.0f);*/

	//

	//backgounds
	Background back1("0.png", 60, 80, .25, .25);
	Background back2("1.png", 650, 80, .25, .25);
	Background back3("3.png", 60, 500, .25, .25);
	Background back4("4.png", 650, 500, .25, .25);
	Background generalbackground("0.png", 0, 0, 3.0, 4.0);
	Clock clock2;
	int score = 0;


	//Game Sounds

	// Background music
	SoundBuffer backgroundmusicBuffer;
	Sound backgroundsound;
	bool firstMusic = true;
	if (!backgroundmusicBuffer.loadFromFile("Audio/supermusic.wav"))
		cout << ("AUDIO NOT FOUND!!");
	backgroundsound.setBuffer(backgroundmusicBuffer);


	////main menu select music
	//SoundBuffer menuMusicBuffer;
	//Sound menuMusicSound;
	//bool secondmusic = true;
	//if (!menuMusicBuffer.loadFromFile("Audio/supermusic.wav"))
	//    cout << ("AUDIO NOT FOUND!!");
	//menuMusicSound.setBuffer(backgroundmusicBuffer);

	//play game music
	SoundBuffer gameplayBuffer;
	Sound gameplaySound;
	bool thirdmusic = true;
	gameplayBuffer.loadFromFile("Audio/playgame.wav");
	if (!gameplayBuffer.loadFromFile("Audio/playgame.wav"))
		cout << ("AUDIO NOT FO0UND!!");
	gameplaySound.setBuffer(backgroundmusicBuffer);



	/// main loop game: 


	bool ismuted = false;
	bool reset = false;


	MainMenu button1(500, 200, 500, 200, "Play");
	button1.selectandunselect();
	MainMenu button2(500, 300, 500, 300, "About");
	MainMenu button3(500, 400, 500, 400, "Credits");
	MainMenu button4(500, 500, 500, 500, "Exit");

	MainMenu buttonE(500, 200, 500, 200, "Easy");
	buttonE.selectandunselect();
	MainMenu buttonH(500, 300, 500, 300, "Hard");


	//Credits creditgame(500, 200, 500, 200, "Credits go to Farah Elsayed 202100258, Arwa Aly 202100362, Nada AlRashidy 202101093");

	while (window.isOpen())
	{
		givemetime = time(NULL);
		timee.setString(ctime(&givemetime));
		givemetime4 = time(0) % 100;
		cout << givemetime4 << endl;
		score++;
		bool downpressed = true;
		Clock clock2;
		unsigned int seconds = static_cast<unsigned int>(clock2.getElapsedTime().asSeconds());
		Text elapsed1text;
		elapsed1text.setString(to_string(givemetime4));
		elapsed1text.setCharacterSize(20);
		elapsed1text.setPosition(100, 00);

		f.loadFromFile("Fonts/Minecraft.ttf");
		elapsed1text.setFont(f);
		sf::Event event;

		while (window.pollEvent(event))
		{

			processEvents(event, back1, back2, back3, back4, backgroundsound, button1, button2, button3, button4, buttonE, buttonH, ismuted, dino, dinoII);
			if (state == "play") {
				dino.jump(event);


			}

		}
		deltaTime = clock.restart().asSeconds();

		window.clear();
		Render(deltaTime, thirdmusic, gameplaySound, generalbackground, button1, button2, button3, button4, buttonE, buttonH, back1, back2, back3, back4, firstMusic, backgroundsound, dino1Player, dino2Player, dino3Player, dino1, dino2, dino3, rect1, rect2, rect3, dino, timee, dinoII, createdbutton, hittable1Enemy, enemy1, enemy2, hittable2Enemy, treasure2, hittable2Treasure, heart1, hittable1Heart, treasure1, hittable1Treasure, elapsed1text, bullet1, hittable1bullet);

	}
}

void Game::processEvents(Event event, Background& back1, Background& back2, Background& back3, Background& back4, Sound& backgroundsound, MainMenu& button1, MainMenu& button2, MainMenu& button3, MainMenu& button4, MainMenu& buttonE, MainMenu& buttonH, bool& ismuted, IDino& dino, IDino& dinoII)
{
	if (event.type == sf::Event::Closed)
		window.close();

	if (state == "initial") {
		if (event.type == Event::KeyReleased && event.key.code == Keyboard::M && !ismuted) // to Mute
		{
			backgroundsound.setVolume(0);
			ismuted = true;
		}
		else  if (ismuted && event.type == Event::KeyReleased && event.key.code == Keyboard::M) //to Play
		{
			ismuted = false;
			backgroundsound.setVolume(100);
		}
		if (event.type == Event::KeyReleased && event.key.code == Keyboard::Enter)
		{
			state = "mainmenu";
			backgroundsound.stop();
		}
	}
	else if (state == "mainmenu") {

		if (button1.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Down)
		{
			button1.selectandunselect();
			button2.selectandunselect();
		}
		else if (button2.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Down)
		{
			button2.selectandunselect();
			button3.selectandunselect();
		}
		else if (button3.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Down)
		{
			button3.selectandunselect();
			button4.selectandunselect();
		}
		else if (button4.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Up)
		{
			button4.selectandunselect();
			button3.selectandunselect();
		}
		else if (button3.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Up)
		{
			button3.selectandunselect();
			button2.selectandunselect();
		}
		else if (button2.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Up)
		{
			button2.selectandunselect();
			button1.selectandunselect();
		}
		if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
		{
			state = "initial";
		}

		if (event.type == Event::KeyReleased && event.key.code == Keyboard:: P)
		{
			state = "Profile";
		}

		if (button1.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Enter) {
			state = "difficultyselection";
		}

		if (button2.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Enter) {
			state = "About";
		}
		if (button3.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Enter) {
			state = "Credits";
		}
		if (button4.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Enter) {
			window.close();
		}

	}
	else if (state == "Credits")
	{
		if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
		{
			state = "mainmenu";
		}

	}
	else if (state == "About")
	{
		if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
		{
			state = "mainmenu";
		}

	}

	else if (state == "play")
	{
		//dino.jump(event);
		if (state == "play" && event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
		{
			state = "backgroundselect";
		}
	}

	else if (state == "difficultyselection")
	{
		if (buttonE.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Down)
		{
			buttonE.selectandunselect();
			buttonH.selectandunselect();
		}

		else if (buttonH.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Up)
		{

			buttonH.selectandunselect();
			buttonE.selectandunselect();
		}
		if (buttonH.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Enter) {
			Difficulty = "Hard";
			state = "backgroundselect";
		}

		if (buttonE.isselected && event.type == Event::KeyReleased && event.key.code == Keyboard::Enter) {
			Difficulty = "Easy";
			state = "backgroundselect";
		}

		if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
		{
			state = "mainmenu";

		}
		if (event.type == Event::KeyReleased && event.key.code == Keyboard::Enter)
		{
			state = "backgroundselect";
		}

	}
	else if (state == "Dinoselection") {
		if (dino.isHoveredOver(window.getPosition().x, window.getPosition().x) && Mouse::isButtonPressed(Mouse::Left)) {
			dinoGame = dino;
			state = "play";
		}
		else if (dinoII.isHoveredOver(window.getPosition().x, window.getPosition().x) && Mouse::isButtonPressed(Mouse::Left)) {
			dinoGame = dinoII;
			state = "play";
		}
		else if (Mouse::isButtonPressed(Mouse::Left)) {
			dinoGame = dinoII;
			state = "play";
		}
		if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
		{
			state = "backgroundselect";
		}
	}
	else if (state == "backgroundselect")
	{

		if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
		{
			state = "difficultyselection";
		}


		if (back1.ishoveredover(window.getPosition().x, window.getPosition().x) && Mouse::isButtonPressed(Mouse::Left))
		{
			/*back1.getsprite().scale(1.0/, 1.0);
			back1.getsprite().setPosition(0, 0);*/
			backgound = back1.getsprite();
			state = "Dinoselection";
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
				state = "mainmenu";
		}
		if (back2.ishoveredover(window.getPosition().x, window.getPosition().x) && Mouse::isButtonPressed(Mouse::Left))
		{
			/*back2.getsprite().scale(1.0 / .25, 1.0 / .25);
			back2.getsprite().setPosition(0, 0);*/
			backgound = back2.getsprite();
			state = "Dinoselection";
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
				state = "mainmenu";

		}
		if (back3.ishoveredover(window.getPosition().x, window.getPosition().x) && Mouse::isButtonPressed(Mouse::Left))
		{
			/*back3.getsprite().scale(1.0 / .25, 1.0 / .25);
			back3.getsprite().setPosition(0, 0);*/
			backgound = back3.getsprite();
			state = "Dinoselection";
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
				state = "mainmenu";
		}
		if (back4.ishoveredover(window.getPosition().x, window.getPosition().x) && Mouse::isButtonPressed(Mouse::Left))
		{
			/*back4.getsprite().scale(1.0 / .25, 1.0 / .25);
			back4.getsprite().setPosition(0, 0);*/
			backgound = back4.getsprite();
			state = "Dinoselection";
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace)
				state = "mainmenu";
		}
		backgound.scale(2.5, 3);
	}
}
/*if (state == "mainmenu") {

	 if (event.type == Event::KeyReleased && event.key.code == Keyboard::BackSpace) {
		 state = "initial";++//*
	 }*/

	 //mute feature





Game::Game()
{
	state = "initial";
	//window.create
	state = "initial";
	int x;
	int y;
	ifstream input("game.txt");
	input >> x;
	input >> y;
	scroll1 = x;
	live = y;
	cout << "------" << x << "-------";
	cout << "------" << x << "-------";
	//window.create

}

void Game::Render(float& deltaTime, bool& thirdmusic, Sound& gameplaySound, Background& generalbackground, MainMenu& button1, MainMenu& button2, MainMenu& button3, MainMenu& button4, MainMenu& buttonE, MainMenu& buttonH, Background& back1, Background& back2, Background& back3, Background& back4, bool& firstMusic, Sound& backgroundsound, Dino& dino1Player, Dino& dino2Player, Dino& dino3Player, RectangleShape& dino1, RectangleShape& dino2, RectangleShape& dino3, Backgroundn& rect1, Backgroundn& rect2, Backgroundn& rect3, IDino& dino
	, Text& time1, IDino& dinoII, Sprite createdbutton, Hittable& hittable1Enemy, RectangleShape& enemy1, RectangleShape& enemy2, Hittable& hittable2Enemy, RectangleShape& treasure1, Hittable& hittable1Treasure, RectangleShape& treasure2, Hittable& hittable2Treasure, RectangleShape& heart1, Hittable& hittable1Heart, Text& elapsed1text, RectangleShape& bullet1, Hittable& hittable1bullet)
{
	x = 7;
	if (state == "play")
	{
		givemetime4 == 0;
		/*
		int x = 0;
		srand(time(0));
		for (int j = 0; j < 10; j++)
		{
			x = (rand() % 10) + 1;
		}
		cout << deltaTime;
		*/
		backgound.setPosition(0, 0);
		int tiles = ceil(1080 / ((backgound.getTexture()->getSize().x) * .25)) + 1;
		for (int i = 0; i < tiles; i++) {
			backgound.setPosition((i * 1024) + scroll, 0);
			window.draw(backgound);
			scroll -= 3;
		}
		if (abs(scroll) > ((backgound.getTexture()->getSize().x))) {
			scroll = 0;
		}

		window.draw(dino.d);
		dino.update(deltaTime);
		if (x == 0 || x == 1 || x == 2)
		{
			enemy2.setTextureRect(hittable2Enemy.uvRect);
			hittable2Enemy.Update(0, deltaTime);
			int tiles1 = ceil(1080 / ((enemy2.getTexture()->getSize().x))) + 1;
			for (int i = 0; i < tiles1; i++) {
				enemy2.setPosition((i * 420) + scroll1, 660);
				scroll1 -= 1;
			}
			window.draw(enemy2);
			dino.is_collision(enemy2);
			if (dino.get_life() == 0)
			{
				state = "Endgame";
			}
		}
		else if (x == 3) {

			treasure1.setTextureRect(hittable1Treasure.uvRect);
			hittable1Treasure.Update(0, deltaTime);
			int tiles1 = ceil(1080 / ((treasure1.getTexture()->getSize().x))) + 1;
			for (int i = 0; i < tiles1; i++) {
				treasure1.setPosition((i * 420) + scroll1, 660);
				scroll1 -= 1;
			}
			window.draw(treasure1);
			dino.is_collision(treasure1);
			if (dino.get_life() == 0)
			{
				state = "Endgame";
			}
		}
		else if (x == 5) {
			treasure2.setTextureRect(hittable2Treasure.uvRect);
			hittable2Treasure.Update(0, deltaTime);
			int tiles1 = ceil(1000 / ((treasure2.getTexture()->getSize().x))) + 1;
			for (int i = 0; i < tiles1; i++) {
				treasure2.setPosition((i * 420) + scroll1, 660);
				scroll1 -= 1;
			}
			window.draw(treasure2);
			dino.is_collision(treasure2);
			if (dino.get_life() == 0)
			{
				state = "Endgame";
			}
		}
		else if (x == 6) {
			heart1.setTextureRect(hittable1Heart.uvRect);
			hittable1Heart.Update(0, deltaTime);
			int tiles1 = ceil(1080 / ((heart1.getTexture()->getSize().x))) + 1;
			for (int i = 0; i < tiles1; i++) {
				heart1.setPosition((i * 420) + scroll1, 660);
				scroll1 -= 1;
			}
			window.draw(heart1);
			dino.is_collision(heart1);
			if (dino.get_life() == 0)
			{
				state = "Endgame";
			}
		}
		else if (x == 7) {
			bullet1.setTextureRect(hittable1bullet.uvRect);
			hittable1bullet.Update(0, deltaTime);
			enemy1.setTextureRect(hittable1Enemy.uvRect);
			hittable1Enemy.Update(0, deltaTime);
			int tiles1 = ceil(1080 / ((enemy1.getTexture()->getSize().x))) + 1;
			for (int i = 0; i < tiles1; i++) {
				enemy1.setPosition((i * 600) + scroll1, 660);
				scroll1 -= 1;
			}
			window.draw(enemy1);
			int tiles2 = ceil(1080 / ((bullet1.getTexture()->getSize().x))) + 1;
			for (int j = 0; j < tiles2; j++) {
				bullet1.setPosition((j * 600) + scroll2, 650);
				scroll2 -= 5;
			}

			if (enemy1.getPosition().x < -20) {
				scroll1 = 0;
			}
			window.draw(bullet1);
			if(dino.is_collision(bullet1))
			{
				;
			}
			dino.is_collision(enemy1);
			if (dino.get_life() == 0)
			{
				state = "Endgame";
			}
		}
		window.draw(elapsed1text);

	}
	else if (state == "mainmenu")
	{
		window.draw(generalbackground.getsprite());
		window.draw(button1.getshape());
		window.draw(button1.getText());
		window.draw(button2.getshape());
		window.draw(button2.getText());
		window.draw(button3.getshape());
		window.draw(button3.getText());
		window.draw(button4.getshape());
		window.draw(button4.getText());
		window.draw(time1);
		window.draw(createdbutton);
	}
	else if (state == "backgroundselect")
	{
		window.draw(back1.getsprite());
		window.draw(back2.getsprite());
		window.draw(back3.getsprite());
		window.draw(back4.getsprite());
	}
	else if (state == "initial")
	{
		if (firstMusic) {
			backgroundsound.play();

			backgroundsound.setVolume(50);
			firstMusic = false;
		}
		dino1Player.Update(0, deltaTime);
		dino1.setTextureRect(dino2Player.uvRect);

		dino2Player.Update(0, deltaTime);
		dino2.setTextureRect(dino2Player.uvRect);
		dino3Player.Update(0, deltaTime);
		dino3.setTextureRect(dino2Player.uvRect);

		rect1.setRectColor(260, 270, 105);
		rect1.setPose(0, 0);
		rect2.setRectColor(240, 210, 100);
		rect2.setPose(400, 0);
		rect3.setRectColor(240, 280, 107);
		rect3.setPose(800, 0);
		rect1.draw(window);
		rect2.draw(window);
		rect3.draw(window);
		rect1.displayText(window);
		window.draw(dino1);
		window.draw(dino2);
		window.draw(dino3);
	}
	else if (state == "Credits")
	{
		Text credittext;
		Font creditfont;
		creditfont.loadFromFile("Fonts/Minecraft.ttf");
		credittext.setFont(creditfont);
		//credittext.setColor(Color::Black);
		credittext.setString("Farah 202100258\nNada 202101093\nArwa 202100362");
		credittext.setPosition(400, 280);
		window.draw(credittext);
	}
	else if (state == "About")
	{
		Text credittext;
		Font creditfont;
		creditfont.loadFromFile("Fonts/Minecraft.ttf");
		credittext.setFont(creditfont);
		//credittext.setColor(Color::Black);
		credittext.setString("press enter to procedd and backspace to go back");
		credittext.setPosition(300, 280);
		window.draw(credittext);
	}
	else if (state == "difficultyselection")
	{
		window.draw(generalbackground.getsprite());
		window.draw(buttonE.getshape());
		window.draw(buttonE.getText());
		window.draw(buttonH.getshape());
		window.draw(buttonH.getText());
	}

	else if (state == "Dinoselection")
	{

		window.draw(dino.d);
		window.draw(dinoII.d);
	}

	window.display();
	//else if (state == "Profile")
	//{
	//	Profile pro;
	//	vector <Profile> profiles = pro.loadProfiles();
	//	string CurrentP_Name = "Visitor";
	//	Profile* CurrentP = nullptr;

	//	Font creditfont;

	//	Text P_Status;
	//	P_Status.setFont(creditfont);
	//	P_Status.setCharacterSize(24);
	//	P_Status.setString("Current Profile ");
	//	P_Status.setPosition(200, 100);

	//	Text P_Name;
	//	P_Name.setFont(creditfont);
	//	P_Name.setCharacterSize(20);
	//	P_Name.setString(CurrentP_Name);
	//	P_Name.setPosition(200, 150);

	//	Text BestScoreTitle;
	//	BestScoreTitle.setFont(creditfont);
	//	BestScoreTitle.setCharacterSize(24);
	//	BestScoreTitle.setString("Your Best Scores");
	//	BestScoreTitle.setPosition(200, 200);

	//	Text BestScore;
	//	BestScore.setFont(creditfont);
	//	BestScore.setCharacterSize(20);
	//	if (CurrentP)
	//	{
	//		BestScore.setString(to_string(CurrentP->getBestScore()));
	//	}
	//	else
	//	{
	//		BestScore.setString("You have no scores availibe");
	//	}
	//	BestScore.setPosition(200, 250);

	//	Text CreateProfile;
	//	CreateProfile.setFont(creditfont);
	//	CreateProfile.setCharacterSize(24);
	//	CreateProfile.setString("Create Profile");
	//	CreateProfile.setPosition(200, 300);

	//	Text SelectProfile;
	//	SelectProfile.setFont(creditfont);
	//	SelectProfile.setCharacterSize(24);
	//	SelectProfile.setString("Select Profile ");
	//	SelectProfile.setPosition(200, 350);


	//	window.draw(P_Status);
	//	window.draw(P_Name);
	//	window.draw(BestScoreTitle);
	//	window.draw(BestScore);
	//	window.draw(CreateProfile);
	//	window.draw(SelectProfile);

	//	if (Mouse::isButtonPressed(Mouse::Left))
	//	{
	//		Vector2i mousePos = Mouse::getPosition(window);
	//	}
	//	if (CreateProfile.getGlobalBounds().contains(200, 300))
	//	{
	//		string NewProfileName;
	//		cout << "Enter a Profile Name: ";
	//		getline(cin, NewProfileName);
	//		profiles.emplace_back(NewProfileName);
	//		pro.SaveProfiles(profiles);
	//	}
	//	else if (SelectProfile.getGlobalBounds().contains(200, 350))
	//	{
	//		vector <string> profileNames;
	//		for (const auto& profile : profiles)
	//		{
	//			profileNames.push_back(profile.getName());
	//		}
	//		sort(profileNames.begin(), profileNames.end());

	//		//for (const auto& profileName : profileNames)
	//		//{
	//		//    cout << profileName << "(" << to_string(getProfileByName(profiles, profileName)->getBestScore()) << endl;
	//		//}

	//		string SelectedProfileName;
	//		cout << "Select a Profile: ";
	//		getline(cin, SelectedProfileName);
	//		/*    CurrentP = getProfileByName(profiles, SelectedProfileName);*/

	//		if (CurrentP)
	//		{
	//			CurrentP_Name = CurrentP->getName();
	//		}
	//		else
	//		{
	//			CurrentP_Name = "Visitor";
	//		}
	//	}

	//}
}

