#include "Button.h"

Button::Button(int textpx, int textpy, int buttonpx, int buttonpy, string textt)
{
	Vector2f v1(120, 60);
	Vector2f v2(buttonpx, buttonpy);
	Vector2f v3(textpx, textpy);
	buttonshape.setFillColor(Color::Green);
	buttonshape.setSize(v1);
	buttonshape.setPosition(v2);
	text.setPosition(v3);
	font.loadFromFile("Fonts/Arial.ttf");
	text.setFont(font);
	text.setStyle(Text::Bold);
	text.setCharacterSize(15);
	text.setFillColor(Color::Black);
	text.setString(textt);
}

void Button::drawbutton(RenderWindow w)
{
	w.draw(buttonshape);
}

void Button::selectandunselect()
{
	if (isselected)
	{
		isselected = false;
		buttonshape.setFillColor(Color::Green);
	} 
	else 
	{
		buttonshape.setFillColor(Color::Magenta);
		isselected = true;
	}
}

RectangleShape Button::getshape()
{
	return buttonshape;
}

Text Button::getText()
{
	return text;
}

bool Button::getselection()
{
	return isselected;
}



void Button::selected()
{
	isselected = true;
	buttonshape.setFillColor(Color::Magenta);
	
}
void Button::unselected()
{
	isselected = false; 
	buttonshape.setFillColor(Color::Green);
}
