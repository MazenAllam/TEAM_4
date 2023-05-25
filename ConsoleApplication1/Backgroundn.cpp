#include "Backgroundn.h"

void Backgroundn::update(float dt)
{

}

void Backgroundn::draw(RenderWindow& window)
{
    window.draw(rect1);
}

void Backgroundn::displayText(RenderWindow& window)
{
    
    if (!font.loadFromFile("Fonts/Minecraft.ttf"))
        throw("Could not find file");
    text.setFont(font);
   

    text.setCharacterSize(150);
    text.setString("DINO HERO");
    text.setPosition(175.0f, 150.0f);
   
    text.setStyle(Text::Bold);
    text.setOutlineColor(Color::Black);
    text.setOutlineThickness(10.0f);
    window.draw(text);


}

void Backgroundn::setPose(float x, float y)
{

    rect1.setPosition(Vector2f(x, y));

}

void Backgroundn::setRectColor(int x, int y, int z)
{
    rect1.setFillColor(Color(x, y, z));
}

Backgroundn::Backgroundn()
{


  
    rect1.setSize(Vector2f(400, 800));

   



}

Backgroundn::~Backgroundn()
{
}
