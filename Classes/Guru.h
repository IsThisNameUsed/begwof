#pragma once

#include "Fish.h"

class Guru : public Fish
{
public:
	Guru(cocos2d::Node * parent, double _X, double _Y, double _dir);
	~Guru();

	void Draw(float dt);

	float influenceRadius;
};

