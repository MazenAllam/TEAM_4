#include "Hittable.h"

//Hittable::Hittable(string ss, int posx, int posy, float scalex, float scaley)
//{
//	t.loadFromFile(ss);
//	H.setTexture(t);
//	H.scale(scalex, scaley);
//	H.setPosition(posx, posy);
//}
//
//Sprite Hittable::getsprite()
//{
//	return H;
//}


void Hittable::Update(int row, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime;
	if (totalTime > switchTime)
	{
		totalTime = switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}
	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}

Hittable::Hittable(Texture* texture, Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;
	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}

//
//bool Hittable::is_collision(RectangleShape shape)
//{
//	//auto bounds = d.getLocalBounds();
//	//d.setOrigin(bounds.width * 6.f, bounds.height * 6.f);
//	//cout << bounds.width * 6. << endl;
//	////cout << bounds.height * 6. << endl;
//
//
//	//remeber the scale
//	//d.getPosition().x < x.getPosition().x + w && d.getPosition().x + (t.getSize().x*6)>x.getPosition().x + 45 && d.getPosition().y < x.getPosition().y + h && d.getPosition().y + (t.getSize().y * 6)>x.getPosition().y + 25
//	if ((this.getGlobalBounds()).intersects(shape.getGlobalBounds()) && ishit) {
//		life -= 1;
//		cout << "help";
//		ishit = false;
//		return true;
//	}
//	else if (!((d.getGlobalBounds()).intersects(shape.getGlobalBounds())) && !ishit)
//	{
//		// ishit = true;
//		return false;
//	}
//
//	if (shape.getPosition().x < 0) {
//		ishit = true;
//	}
//}


Hittable::~Hittable()
{
}
