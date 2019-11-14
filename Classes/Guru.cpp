#include "Guru.h"
#include "Player.h"

using namespace cocos2d;

Guru::Guru(cocos2d::Node * parent, double _X, double _Y, double _dir, int teamId) : Fish(parent,_X, _Y, _dir)
{
	lineThickness = 1.5;
	influenceRadius = 30;

	this->teamId = teamId;
	this->color = Player::GetColor(teamId);
	Player::RegisterColor(teamId);
}

Guru::~Guru()
{
	Player::RemoveColor(teamId);
}

void Guru::Update(std::vector<std::shared_ptr<Fish>>& fishes, std::list<AreaToAvoid>& obstacles, double width, double length, float dt)
{
	Fish::Update(fishes, obstacles, width, length, dt);
	Influence(fishes);
}

void Guru::Draw(float dt)
{
	Fish::Draw(dt);

	draw->drawCircle(pos, influenceRadius, 360, 24, false, color);
}

void Guru::Influence(std::vector<std::shared_ptr<Fish>>& fishes)
{
	int number = 0;
	auto it = fishes.begin();
	auto end = fishes.end();
	while (it != end)
	{
		Fish* fish = (*it).get();
		if (DistanceSquared(*fish) < influenceRadius * influenceRadius)
		{
			fish->color = color;
		}
		++it;
	}
}
