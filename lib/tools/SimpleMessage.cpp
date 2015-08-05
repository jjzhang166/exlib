#include "SimpleMessage.h"
#include "cocos2d.h"
#include "TipsLayer.h"
#include "LoadingTipsLayer.h"

using namespace cocos2d;
SimpleMessage* SimpleMessage::_simple_message = nullptr;

void SimpleMessage::ShowMessage(std::string _str)
{
	this->addChild(TipsLayer::create(_str),3);
}

bool SimpleMessage::init() {
	if ( !Node::init() ) {
		return false;
	}
	onEnter();
	this->retain();
	return true;
}

SimpleMessage* SimpleMessage::getInstance()
{
	if (_simple_message == NULL)
	{
		_simple_message = SimpleMessage::create();
		_simple_message->setPosition(0,0);
		Director::getInstance()->setNotificationNode(_simple_message);
		return _simple_message;
	}
	return _simple_message;
}

void SimpleMessage::showLoading()
{
	auto layer = LoadingTipsLayer::create();
	layer->setTag(10);
	this->addChild(layer);
}

void SimpleMessage::removeLoading()
{
	this->removeChildByTag(10);
}

void showMessage( std::string msg )
{
	SimpleMessage::getInstance()->ShowMessage(msg);
}

void showLoading()
{
	SimpleMessage::getInstance()->showLoading();
}

void removeLoading()
{
	SimpleMessage::getInstance()->removeLoading();
}
