#include "Guru.h"


Guru::Guru(cocos2d::Node * parent, double _X, double _Y, double _dir) : Fish(parent,_X, _Y, _dir)
{
	lineThickness = 1.5;
	influenceRadius = 30;
}

Guru::~Guru()
{
}

void Guru::Draw(float dt)
{
	Fish::Draw(dt);

	draw->drawCircle(pos, influenceRadius, 360, 24, false, color);
}
