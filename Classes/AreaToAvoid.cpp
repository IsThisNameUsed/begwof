#include "AreaToAvoid.h"



AreaToAvoid::AreaToAvoid(double _x, double _y, double _radius)
{
	pos.x = _x;
	pos.y = _y;
	radius = _radius;
}


AreaToAvoid::~AreaToAvoid()
{
}

double AreaToAvoid::GetRadius()
{
	return radius;
}

void AreaToAvoid::UpdateTime()
{
	remainingTime--;
}

bool AreaToAvoid::IsDead()
{
	return remainingTime <= 0;
}
