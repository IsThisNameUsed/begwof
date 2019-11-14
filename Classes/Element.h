#pragma once

#include "cocos2d.h"

class Element
{
public:
	// General functions
	Element();
	Element(cocos2d::Node* parent);
	Element(int, int);
	~Element();
	virtual void Draw(float dt);

	// Feedback functions
	bool isClicked(cocos2d::Point point);
	void click();

	// Utilities functions
	double Distance(Element* o);
	double DistanceSquared(Element o);

	// Variables
	int id;
	cocos2d::Point pos;
	bool isClickable;
	float clickRadius;
	cocos2d::Color4F color;

protected:
	// Node used to draw lines and circles
	cocos2d::DrawNode* draw;
};

