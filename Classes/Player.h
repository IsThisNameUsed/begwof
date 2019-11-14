#pragma once

#include "cocos2d.h"
#include <map>

class Player
{
public:
	static int GetNextGuruTeam();
	static bool RegisterColor(int color);
	static bool RemoveColor(int color);
	static bool CanCreateGuru();
	static cocos2d::Color4F GetColor(int id);
	static void Reset();

private:
	static int NextIndex();

	static int currentIndex;
	static std::map<int, bool> colorUsed;
	const static std::map<int, cocos2d::Color4F> colorMatch;
};

