#include "Object.h"
#include "math.h"


Object::Object()
{
}

Object::Object(int _posX, int _posY)
{
	posX = _posX;
	posY = _posY;
}

Object::~Object()
{
}

double Object::Distance(Object o)
{
	return sqrt((o.posX - posX)*(o.posX - posX) + (o.posY - posY)*(o.posY - posY));
}

double Object::DistanceCarre(Object o)
{
	return (o.posX - posX)*(o.posX - posX) + (o.posY - posY)*(o.posY - posY);
}
