#include "IDino.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf;
using namespace std;
#include <cmath>

IDino::IDino(string s, double x, double y)
{
	reset = false;
	candoublejump = false;
	dinodown.loadFromFile("DuckSprite.png");
	velocity.x = 0;
	velocity.y = 0;
	t.loadFromFile(s);
	d.setTexture(t);
	d.scale(6, 6);
	d.setPosition(x, y);
	dinojumpBuffer.loadFromFile("Audio/jumping.wav");
	dinojumpSound.setBuffer(dinojumpBuffer);
	dinoducksBuffer.loadFromFile("Audio/jumping.wav");
	dinoducksSound.setBuffer(dinoducksBuffer);
	ishit = true;
	life = 600;
}

IDino::IDino()
{
}

bool IDino::isHoveredOver(int x, int y)
{
	if (Mouse::getPosition().x >= x + d.getPosition().x && Mouse::getPosition().x <= x + d.getPosition().x + t.getSize().x * 6.0 && Mouse::getPosition().y >= y + d.getPosition().y && Mouse::getPosition().y <= y + d.getPosition().y + t.getSize().y * 6.0) {
		return true;
	}
	else {
		return false;
	}
}

void IDino::jump(Event event)
{
	if (event.type == Event::KeyReleased && event.key.code == Keyboard::W && d.getPosition().y > 635 && !Keyboard::isKeyPressed(Keyboard::S)) {
		velocity.y = -sqrt(2.0f * 981.0f * 200.0);
		candoublejump = true;
		dinojumpSound.play();
		dinojumpSound.setVolume(100);

	}   //200=  jumpheight
	else if (event.type == Event::KeyReleased && event.key.code == Keyboard::W && candoublejump)
	{
		dinojumpSound.play();
		dinojumpSound.setVolume(100);
		velocity.y = -sqrt(2.0f * 981.0f * 200.0);
		candoublejump = false;
	}
}


void IDino::update(float dt) {
	if (this->d.getPosition().y < 640)
	{
		velocity.y += 981.0f * dt;
	}
	this->d.move(0, velocity.y * dt);
	if (this->d.getPosition().y > (640) && !Keyboard::isKeyPressed(Keyboard::S))
	{
		this->d.setPosition(50, 640);
	}
	if (Keyboard::isKeyPressed(Keyboard::S) && d.getPosition().y > 630) {
		dinoducksSound.play();
		dinoducksSound.setVolume(100);
		d.setTexture(dinodown);
		d.setPosition(47, 640);
		reset = 1;
	}

	if (reset && !Keyboard::isKeyPressed(Keyboard::S)) {
		d.setPosition(50, 640);
		d.setTexture(t);
		reset = 0;
	}
}

bool IDino::is_collision(RectangleShape shape)
{
	//auto bounds = d.getLocalBounds();
	//d.setOrigin(bounds.width * 6.f, bounds.height * 6.f);
	//cout << bounds.width * 6. << endl;
	////cout << bounds.height * 6. << endl;


	//remeber the scale
	//d.getPosition().x < x.getPosition().x + w && d.getPosition().x + (t.getSize().x*6)>x.getPosition().x + 45 && d.getPosition().y < x.getPosition().y + h && d.getPosition().y + (t.getSize().y * 6)>x.getPosition().y + 25
	if ((d.getGlobalBounds()).intersects(shape.getGlobalBounds()) && ishit) {
			life += 1;

		ishit = false;
		return true;
	}
	else if (!((d.getGlobalBounds()).intersects(shape.getGlobalBounds())) && !ishit)
	{
		ishit = true;
		return false;
	}
}

bool IDino::is_collision1(RectangleShape shape)
{
	//auto bounds = d.getLocalBounds();
	//d.setOrigin(bounds.width * 6.f, bounds.height * 6.f);
	//cout << bounds.width * 6. << endl;
	////cout << bounds.height * 6. << endl;


	//remeber the scale
	//d.getPosition().x < x.getPosition().x + w && d.getPosition().x + (t.getSize().x*6)>x.getPosition().x + 45 && d.getPosition().y < x.getPosition().y + h && d.getPosition().y + (t.getSize().y * 6)>x.getPosition().y + 25
	if ((d.getGlobalBounds()).intersects(shape.getGlobalBounds()) && ishit1) {
		if ( life < 3)
		{
			life += 1;
		}
		else if ( life > 0)
		{
			life -= 1;
		}
		ishit1 = false;
		return true;
	}
	else if (!((d.getGlobalBounds()).intersects(shape.getGlobalBounds())) && !ishit1)
	{
		ishit1 = true;
		return false;
	}
}

int IDino::get_life()
{
	return life;
}
