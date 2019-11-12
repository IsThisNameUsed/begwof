#pragma once
#include "Element.h"

class Poisson: public Element
{
public:
	Poisson(cocos2d::Node* parent);
	~Poisson();

	virtual void update(float dt);

protected:
	cocos2d::Point velocity;
	float lineLength;
	float lineThickness;

	// PLACEHOLDER
	float time = 0;
};