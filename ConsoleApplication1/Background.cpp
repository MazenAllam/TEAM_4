#include "Background.h"

Background::Background(string ss, int posx, int posy, float scalex, float scaley)
{
	t.loadFromFile(ss);
	s.setTexture(t);
	s.scale(scalex, scaley);
	s.setPosition(posx, posy);
}

Sprite Background::getsprite()
{
	return s;
}

bool Background::ishoveredover(int x, int y)
{
	if (Mouse::getPosition().x >= x + s.getPosition().x && Mouse::getPosition().x <= x + s.getPosition().x + t.getSize().x * 0.25 && Mouse::getPosition().y+180 >= y + s.getPosition().y && Mouse::getPosition().y+180 <= y + s.getPosition().y + t.getSize().y * 0.25)
	{
		return true;
	}
	else {
		return false;
	}
}

Texture Background::get_Size()
{
	return t;
}


