#include "LoadingSprite.h"


bool LoadingSprite::init()
{
	if (!Sprite::initWithFile("ui/loading.png"))
	{
		return false;
	}

	RotateTo* rotateTo = RotateTo::create(0.5f,-720);
	RepeatForever * repeatForever =RepeatForever::create(rotateTo);
	this->runAction(repeatForever);
	return true;
}
