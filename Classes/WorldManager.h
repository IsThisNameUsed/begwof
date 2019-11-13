#pragma once
#include "cocos2d.h"
#include "Fish.h"
#include "AreaToAvoid.h"
#include "stdlib.h"
#include "Fish.h"
#include "Guru.h"
class WorldManager
{
public:
	WorldManager(cocos2d::Node* parent,int _fishNumber, double _width, double _length);
	~WorldManager();
	void AddObstacle(double _posX, double _posY, double _radius);
	void UpdateObstacles();
	void UpdateFishes(float dt);
	void UpdateWorld(float dt);
protected:
	std::vector<Fish> fishes;
	std::list<AreaToAvoid> obstacles;
	double width;
	double length;
};

