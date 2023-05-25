#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Dino
{
private:
	Vector2u imageCount;
	Vector2u currentImage;
	float totalTime;
	float switchTime;
 

public:
	Dino(Texture* texture, Vector2u imageCount, float switchTime);
	~Dino();
	void Update(int row, float deltaTime);
	IntRect uvRect;
};

