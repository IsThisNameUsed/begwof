#include "WorldManager.h"
#include "math.h"


WorldManager::WorldManager(cocos2d::Node* parent,int _fishNumber, double _width, double _length)
{
	height = _length;
	width = _width;
	obstacles = *(new std::list<AreaToAvoid>());
	fishes = *(new std::vector<Fish>());
	srand(time(NULL));
	for (int i = 0; i < _fishNumber; i++)
	{
		double x = ((double)rand() / RAND_MAX)* width;
		double y = ((double)rand() / RAND_MAX)* height;
		//x = 50;
		//y = 75 + i * 10;
		double dir = ((double)rand() / RAND_MAX) * 2 * 3.14f;
		fishes.push_back(Fish(parent,x, y, dir));
	}
}


WorldManager::~WorldManager()
{
}

void WorldManager::AddObstacle(double _posX, double _posY, double _radius)
{
	obstacles.push_back(*(new AreaToAvoid(_posX, _posY, _radius)));
}

void WorldManager::UpdateObstacles()
{
	auto it = obstacles.begin();
	auto end = obstacles.end();
	while (it !=end)
	{
		(*it).UpdateTime();
		if ((*it).IsDead())
		{
			it = obstacles.erase(it);
		}
		else it++;
	}
}
void WorldManager::UpdateFishes(float dt)
{
	for (int i = 0; i < fishes.size(); i++)
	{
		fishes.at(i).Update(fishes, obstacles, width, height, dt);
	}
}
void WorldManager::UpdateWorld(float dt)
{
	UpdateObstacles();
	UpdateFishes(dt);
}