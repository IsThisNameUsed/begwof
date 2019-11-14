#pragma once

#include "cocos2d.h"
#include <map>

class Player
{
public:
	static cocos2d::Color4F GetNextGuruColor();
	static bool RegisterColor(cocos2d::Color4F color);
	static bool RemoveColor(cocos2d::Color4F color);
	static bool CanCreateGuru();

private:
	using Map = std::map <cocos2d::Color4F, bool>;
	static const Map& getColors() {
		static const Map ret{
			{cocos2d::Color4F::RED, false}
		};
		return ret;
	}

	//static std::map<cocos2d::Color4F, bool> colors;

};

