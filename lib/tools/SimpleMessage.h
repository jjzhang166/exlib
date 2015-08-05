#ifndef _SIMPLE_MESSAGE_H_
#define _SIMPLE_MESSAGE_H_

#include "cocos2d.h"
#include <string>
#include "../data/CSVManager.h"

class SimpleMessage :public cocos2d::Node
{
public:
	void ShowMessage(std::string _str);
	static SimpleMessage* getInstance();
	
	void showLoading();
	void removeLoading();
protected:
	virtual bool init();
private:
	CREATE_FUNC(SimpleMessage);
	static SimpleMessage* _simple_message;
};

void showMessage(std::string msg);

void showLoading();
void removeLoading();
#endif