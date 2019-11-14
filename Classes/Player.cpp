#include "Player.h" 

using namespace cocos2d;

std::map<int, bool> Player::colorUsed{
	{1, false},
	{2, false},
	{3, false},
	{4, false},
	{5, false},
	{6, false},
};

const std::map<int, Color4F> Player::colorMatch{
	{1, Color4F::RED},
	{2, Color4F::BLUE},
	{3, Color4F::GREEN},
	{4, Color4F::MAGENTA},
	{5, Color4F::ORANGE},
	{6, Color4F::YELLOW},
};

int Player::currentIndex = (rand() % Player::colorUsed.size()) + 1;


int Player::GetNextGuruTeam()
{
	int triesLeft = colorUsed.size();
	while (triesLeft > 0)
	{
		--triesLeft;
		if (!colorUsed.at(currentIndex))
			return currentIndex;

		NextIndex();
	}
	return 0;
}

bool Player::RegisterColor(int id)
{
	auto foundColorUsed = colorUsed.find(id);

	// If no color match
	if (foundColorUsed == colorUsed.end())
		return false;

	// Color already taken
	if (foundColorUsed->second)
		return false;

	foundColorUsed->second = true;
	return true;
}

bool Player::RemoveColor(int id)
{
	auto foundColorUsed = colorUsed.find(id);

	// If no color match
	if (foundColorUsed == colorUsed.end())
		return false;

	// Color already free
	if (!foundColorUsed->second)
		return false;

	foundColorUsed->second = false;
}

bool Player::CanCreateGuru()
{
	return GetNextGuruTeam() != 0;
}

cocos2d::Color4F Player::GetColor(int id)
{
	auto find = colorMatch.find(id);
	if (find == colorMatch.end())
		return Color4F::WHITE;

	return find->second;
}

void Player::Reset()
{
	auto it = colorUsed.begin();
	auto end = colorUsed.end();
	while (it != end)
	{
		it->second = false;
		++it;
	}
}

int Player::NextIndex()
{
	++currentIndex;
	if (currentIndex > colorUsed.size())
		currentIndex = 1;

	return currentIndex;
}
