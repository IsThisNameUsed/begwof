#pragma once

#include "Poisson.h"

class Guru : public Poisson
{
public:
	Guru(cocos2d::Node* parent);
	~Guru();

	void update(float dt);

	float influenceRadius;
};

