
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Element.h"
#include "Fish.h"
#include "Guru.h"
#include "WorldManager.h";

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
	bool onClick(cocos2d::Touch * touch, cocos2d::Event * event);

	// variables
	float timeScale = 1;
	float time;
	std::vector<std::unique_ptr<Element>> elements; // TODO change to objects
	std::vector<Fish> fishes;
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
	WorldManager *worldManager;
};

#endif // __HELLOWORLD_SCENE_H__
