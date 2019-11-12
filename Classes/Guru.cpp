#include "Guru.h"


Guru::Guru(cocos2d::Node * parent) : Poisson(parent)
{
	lineThickness = 1.5;
	influenceRadius = 30;
}

Guru::~Guru()
{
}

void Guru::update(float dt)
{
	Poisson::update(dt);

	draw->drawCircle(pos, influenceRadius, 360, 24, false, color);
}
