#include "Poisson.h"

using namespace cocos2d;

Poisson::Poisson(cocos2d::Node * parent) : Element(parent)
{
	velocity = Point(1, 1);
	lineLength = 10;
	lineThickness = 0.5;
}

Poisson::~Poisson()
{
}

void Poisson::update(float dt)
{
	//PLACEHOLDER
	velocity.x = 5;
	velocity.y = std::sin(time) * 5;
	time += dt;
	
	// TODO LOGIC

	pos += velocity * dt;

	Point from = pos;
	Point to = from + velocity.getNormalized() * lineLength;
	
	draw->clear();
	draw->drawSegment(from, to, lineThickness, color);
	//draw->drawLine(from, to, color);
	draw->drawCircle(from, clickRadius, 360, 12, false, color);
}
