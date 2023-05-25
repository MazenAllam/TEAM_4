#include "MainMenu.h"

MainMenu::MainMenu(int textpx, int textpy, int buttonpx, int buttonpy, string textt)
{
	font.loadFromFile("Fonts/Arial.ttf");
	Vector2f v1(120.f, 60.f);
	buttonshape.setFillColor(Color::Green);
	buttonshape.setSize(v1);
	buttonshape.setPosition(buttonpx, buttonpy);
	text.setFont(font);
	text.setStyle(Text::Bold);
	text.setCharacterSize(15);
	text.setFillColor(Color::Black);
	text.setString(textt);
	text.setPosition(textpx, textpy);
}

void MainMenu::drawbutton(RenderWindow w)
{
	w.draw(buttonshape);
}

void MainMenu::selectandunselect()
{
	if (isselected)
	{
		isselected = false;
		buttonshape.setFillColor(Color::Green);

	}

	else {
		buttonshape.setFillColor(Color::Magenta);
		isselected = true;
	}
}

RectangleShape MainMenu::getshape()
{
	return buttonshape;
}

Text MainMenu::getText()
{
	return text;
}

bool MainMenu::getselection()
{
	return isselected;
}



void MainMenu::selected()
{
	isselected = true;
	buttonshape.setFillColor(Color::Magenta);

}
void MainMenu::unselected()
{
	buttonshape.setFillColor(Color::Green);
}