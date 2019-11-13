#pragma once

#include "cocos2d.h"
#include "Fish.h"

class Guru : public Fish
{
public:
	Guru(cocos2d::Node * parent, double _X, double _Y, double _dir, cocos2d::ccColor4F color);
	~Guru();

	void Update(std::vector<Fish> &fishes, std::list<AreaToAvoid> &obstacles, double width, double length, float dt) override;
	void Draw(float dt);
	void Influence(std::vector<Fish> &fishes);
	float influenceRadius;
};

