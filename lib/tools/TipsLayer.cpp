#include "TipsLayer.h"
#include "../data/CSVManager.h"
#include "../config.h"


TipsLayer* TipsLayer::create(string id)
{
	TipsLayer* pRet = new TipsLayer();
	if (pRet && pRet->init(id))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool TipsLayer::init(string id)
{
	if (!Layer::init())
	{
		return false;
	}

	touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(TipsLayer::onTouchBegan,this);
	touchListener->onTouchMoved = CC_CALLBACK_2(TipsLayer::onTouchMoved,this);
	touchListener->onTouchEnded = CC_CALLBACK_2(TipsLayer::onTouchEnded, this);
	this->_eventDispatcher->addEventListenerWithFixedPriority(touchListener,-128);
//	dispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	MenuItemImage* tips = MenuItemImage::create(
		"ui/tips.png",
		"ui/tips.png",
		CC_CALLBACK_1(TipsLayer::menuEndCallback,this)
		);
	tips->setPosition(270,480);

	Menu* menu = Menu::create(tips,nullptr);
	menu->setPosition(0,0);
	this->addChild(menu);

	TTFConfig config(FONT_NAME,30);
	Label* msgLabel = Label::createWithTTF(config,id,TextHAlignment::CENTER);
// #if CC_TARGET_PLATFORM == CC_PLATFORM_WP8
// 	Label* msgLabel = Label::create(id,"fonts/simhei.ttf",30);
// #else
// 	Label* msgLabel = Label::create(id,"",30);
// #endif
//	msgLabel->setAlignment(TextHAlignment::CENTER);
	msgLabel->setPosition(270,480);
	this->addChild(msgLabel);

	_time = 2;
	this->schedule(schedule_selector(TipsLayer::tick),1.0f);

	return true;
}

void TipsLayer::menuEndCallback( Ref* pSender )
{
//	this->removeFromParent();
}

void TipsLayer::tick( float dt )
{
	_time--;
	if (_time <= 0)
	{
		this->removeFromParent();
	}
}

TipsLayer::~TipsLayer()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeEventListener(touchListener);
}

bool TipsLayer::onTouchBegan( Touch *pTouch, Event *pEvent )
{
	this->removeFromParent();
	return false;
}

void TipsLayer::onTouchMoved( Touch *touch, Event *unused_event )
{

}

void TipsLayer::onTouchEnded( Touch *touch, Event *unused_event )
{

}
