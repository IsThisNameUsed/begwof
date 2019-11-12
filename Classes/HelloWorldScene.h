
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Poisson.h"

class HelloWorld : public cocos2d::Scene
{
public:
	// main functions
    virtual bool init() override;
	void update(float dt) override;

	// static thingy
    static cocos2d::Scene* scene();

    // callbacks
    void menuCloseCallback(Ref* sender);
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event);
	void onClick(cocos2d::Touch * touch, cocos2d::Event * event);

	// variables
	float timeScale = 1;
	float time;
	std::vector<int> objects; // TODO change to objects

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
