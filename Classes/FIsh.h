#pragma once
#include "Element.h"
#include "AreaToAvoid.h"

class Fish: public Element
{
public:
	Fish();
	Fish(cocos2d::Node* parent, double _X, double _Y, double _dir);
	~Fish();
	double getVelocityX();
	double getVelocityY();
	virtual void Draw(float dt);
	void Update(std::vector<Fish> &fishes, std::list<AreaToAvoid> &obstacles, double width, double length,float dt);

	static const double STEP;
	static const double DISTANCE_MIN;
	static const double DISTANCE_MIN_SQUARED;
	static const double DISTANCE_MAX;
	static const double DISTANCE_MAX_SQUARED;

protected:
	void UpdatePosition();
	bool InAlignment(Fish p);
	double DistanceFromWall(double wallXMin, double wallXMax, double wallYMin, double wallYMax);
	void NormalizeVelocity();
	bool AvoidWall(double wallXMin, double wallYMin, double wallXMax, double wallYMax);
	bool AvoidObstacle(std::list<AreaToAvoid> obstacles);
	bool AvoidFish(std::vector<Fish> fishes);
	void CalculateAverageDirection(std::vector<Fish> fishes);
	//void Draw(float dt);
	cocos2d::Point velocity;
	float lineLength;
	float lineThickness;

	// PLACEHOLDER
	float time = 0;
};