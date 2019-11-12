#pragma once
#include "Object.h"

class AreaToAvoid: public Object
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

