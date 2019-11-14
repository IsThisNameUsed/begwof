#include "WorldManager.h"
#include "math.h"


WorldManager::WorldManager(cocos2d::Node* parent,int _fishNumber, double _width, double _length)
{
	height = _length;
	width = _width;
	obstacles = std::list<AreaToAvoid>();
	fishes = std::vector<std::shared_ptr<Fish>>();
	srand(time(NULL));
	for (int i = 0; i < _fishNumber; i++)
	{
		double x = ((double)rand() / RAND_MAX)* width;
		double y = ((double)rand() / RAND_MAX)* height;
		double dir = ((double)rand() / RAND_MAX) * 2 * 3.14f;
		fishes.push_back(std::shared_ptr<Fish>(new Fish(parent,x, y, dir)));
	}

	int i = 30;
	while (Player::CanCreateGuru())
	{
		fishes.push_back(std::shared_ptr<Guru>(new Guru(parent, i, 400, 0, Player::GetNextGuruColor())));
		i += 30;
	}

	/*fishes.push_back(std::shared_ptr<Guru>(new Guru(parent, 50, 400, 0, cocos2d::ccColor4F::RED)));
	fishes.push_back(std::shared_ptr<Guru>(new Guru(parent, 150, 400, 0, cocos2d::ccColor4F::GREEN)));
	fishes.push_back(std::shared_ptr<Guru>(new Guru(parent, 250, 400, 0, cocos2d::ccColor4F::BLUE)));
	fishes.push_back(std::shared_ptr<Guru>(new Guru(parent, 350, 400, 0, cocos2d::ccColor4F::MAGENTA)));
	fishes.push_back(std::shared_ptr<Guru>(new Guru(parent, 450, 400, 0, cocos2d::ccColor4F::ORANGE)));*/
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
		Fish* fish = fishes.at(i).get();
		fish->Update(fishes, obstacles, width, height, dt);
	}
}
void WorldManager::UpdateWorld(float dt)
{
	UpdateObstacles();
	UpdateFishes(dt);
}