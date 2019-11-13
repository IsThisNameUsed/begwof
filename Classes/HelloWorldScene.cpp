
#include "HelloWorldScene.h"
#include "WorldManager.h"
#include "AppMacros.h"
#include <iostream>
#include <stdlib.h>
USING_NS_CC;


Scene* HelloWorld::scene()
{
     return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
	auto arenaSize = Point(visibleSize.width, visibleSize.height - 50);

    auto origin = Director::getInstance()->getVisibleOrigin();


    /////////////////////////////
    // 3. add your codes below...

	// Arena border
    auto drawNode = DrawNode::create();
    drawNode->setPosition(Vec2(0, 0));
    addChild(drawNode);

    Rect safeArea = Director::getInstance()->getSafeAreaRect();
    drawNode->drawRect(safeArea.origin, safeArea.origin + safeArea.size, Color4F::BLUE);

	// Keyboard listener
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);

	// Mouse listener
	auto clickListener = EventListenerTouchOneByOne::create();
	clickListener->setSwallowTouches(true);
	clickListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onClick, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(clickListener, this);

	worldManager = new WorldManager(this,150, arenaSize.x, arenaSize.y);


	// Update function call
	this->scheduleUpdate();
	time = 0;

    return true;
}

void HelloWorld::update(float dt)
{
	// Set delta time
	dt *= timeScale;
	time += dt;
	worldManager->UpdateWorld(dt);
	// Update each element
	/*auto it = elements.begin();
	auto end = elements.end();
	while (it != end)
	{
		Element* element = it->get();		
		element->Draw(dt);
		++it;
	}*/
}

// Callback when player press any key
void HelloWorld::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_1)
	{
		timeScale = 0.1;
		CCLOG("time slow");
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_2)
	{
		timeScale = 1.0;
		CCLOG("time normal");
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_3)
	{
		timeScale = 2.0;
		CCLOG("time fast");
	}
}

// Callback when player click with mouse
bool HelloWorld::onClick(Touch* touch, Event* event)
{
	// Check for every element is the player clicked on it
	auto it = elements.begin();
	auto end = elements.end();
	while (it != end)
	{
		Element* element = it->get();
		if (element->isClicked(touch->getLocation()))
		{
			// If the player clicked on an element, notify it
			element->click();
			return true;
		}
		++it;
	}

	return false;
}