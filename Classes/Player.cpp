#include "Player.h" 

using namespace cocos2d;

std::map<Color4F, bool> createMap()
{
	std::map<Color4F, bool> m;
	m[Color4F::RED] = false;
	return m;
}

/*std::map<Color4F, bool> Player::colors {
   {Color4F::RED, false},
   {Color4F::BLUE, false},
   {Color4F::GRAY, false},
   {Color4F::GREEN, false},
   {Color4F::MAGENTA, false},
   {Color4F::ORANGE, false},
   {Color4F::YELLOW, false},
};*/

std::map<Color4F, bool> Player::colors = createMap();

cocos2d::Color4F Player::GetNextGuruColor()
{
	/*for (auto color : colors)
	{
		if (!color.second)
			return color.first;
	}
	*/
	return Color4F::WHITE;
}

bool Player::RegisterColor(cocos2d::Color4F color)
{
	/*auto foundColor = colors.find(color);

	// If no color match
	if (foundColor == colors.end())
		return false;

	// Color already taken
	if (foundColor->second)
		return false;

	foundColor->second = true;*/
	return true;
}

bool Player::RemoveColor(cocos2d::Color4F color)
{
	/*auto foundColor = colors.find(color);

	// If no color match
	if (foundColor == colors.end())
		return false;

	// Color already free
	if (!foundColor->second)
		return false;

	foundColor->second = false;*/
	return true;
}

bool Player::CanCreateGuru()
{
	return GetNextGuruColor() != Color4F::WHITE;
}
