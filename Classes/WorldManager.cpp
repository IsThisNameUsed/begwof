#include "WorldManager.h"
#include "math.h"


WorldManager::WorldManager(cocos2d::Node* parent,int _fishNumber, double _width, double _length)
{
	length = _length;
	width = _width;
	obstacles = *(new std::list<AreaToAvoid>());
	fishes = *(new std::vector<Fish>());
	for (int i = 0; i <= _fishNumber; i++)
	{
		fishes.push_back(*(new Fish(parent,(double)(rand() % 2) *width, (double)(rand() % 2)*length, (double)(rand()%2) * 2 * 3.14f)));
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
		fishes.at(i).Update(fishes, obstacles, width, length, dt);
	}
}
void WorldManager::UpdateWorld(float dt)
{
	UpdateObstacles();
	UpdateFishes(dt);

}