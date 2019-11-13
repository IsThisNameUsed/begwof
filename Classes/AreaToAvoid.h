#pragma once
#include "Element.h"

class AreaToAvoid: public Element
{
public:
	AreaToAvoid(double _x, double _y, double _radius);
	~AreaToAvoid();
	double GetRadius();
	void UpdateTime();
	bool IsDead();
protected:
	double radius;
	int remainingTime;
};

