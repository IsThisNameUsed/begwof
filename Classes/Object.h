#pragma once
class Object
{
public:
	double posX;
	double posY;
	Object();
	Object(int, int);
	~Object();
	double Distance(Object o);
	double DistanceCarre(Object o);
};

