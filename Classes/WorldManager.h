#pragma once
#include "cocos2d.h"
#include "Fish.h"
#include "AreaToAvoid.h"
#include "stdlib.h"
#include "Fish.h"
#include "Guru.h"
#include "Player.h"

class WorldManager
{
public:
	WorldManager(cocos2d::Node* parent,int _fishNumber, double _width, double _length);
	~WorldManager();
	void AddObstacle(double _posX, double _posY, double _radius);
	void UpdateObstacles();
	void UpdateFishes(float dt);
	void UpdateWorld(float dt);
	Fish ReturnGuru(cocos2d::ccColor4F);

protected:
	std::vector<std::shared_ptr<Fish>> fishes;
	std::list<AreaToAvoid> obstacles;
	double width;
	double height;
};

