#include "LoadingTipsLayer.h"
#include "LoadingSprite.h"

bool LoadingTipsLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(LoadingTipsLayer::onTouchBegan,this);
	touchListener->onTouchMoved = CC_CALLBACK_2(LoadingTipsLayer::onTouchMoved,this);
	touchListener->onTouchEnded = CC_CALLBACK_2(LoadingTipsLayer::onTouchEnded, this);
	dispatcher->addEventListenerWithFixedPriority(touchListener,-127);

	LoadingSprite* ls = LoadingSprite::create();
	ls->setPosition(270,480);
	this->addChild(ls);

	return true;
}

void LoadingTipsLayer::menuItemCallback( Ref* pSender )
{

}

bool LoadingTipsLayer::onTouchBegan( Touch *pTouch, Event *pEvent )
{
	return true;
}

void LoadingTipsLayer::onTouchMoved( Touch *touch, Event *unused_event )
{

}

void LoadingTipsLayer::onTouchEnded( Touch *touch, Event *unused_event )
{

}

LoadingTipsLayer::~LoadingTipsLayer()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeEventListener(touchListener);
}
