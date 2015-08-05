#pragma once

#include "cocos2d.h"
#include <string>
USING_NS_CC;
using namespace std;

class TipsLayer : public Layer
{
public:
	static TipsLayer* create(string id);
	virtual bool init(string id);

	void menuEndCallback(Ref* pSender);
	void tick(float dt);

	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
protected:
	EventListenerTouchOneByOne* touchListener;
	TipsLayer(){};
	~TipsLayer();
	int _time;
private:
};