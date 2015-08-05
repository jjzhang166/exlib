#pragma once

#include "cocos2d.h"
#include <string>
USING_NS_CC;
using namespace std;

class LoadingTipsLayer : public Layer
{
public:
	CREATE_FUNC(LoadingTipsLayer);
	virtual bool init();

	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);

	void menuItemCallback(Ref* pSender);

protected:
	LoadingTipsLayer(){};
	~LoadingTipsLayer();
	EventListenerTouchOneByOne* touchListener;
private:
};