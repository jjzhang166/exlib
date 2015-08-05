#include "PostMsg.h"
#include "stdio.h"
#include <iostream>
#include "CURLCode.h"

using namespace std;
string PostMsg::getMsg()
{
	return this->_msg;
}

void PostMsg::pushCmd(const char* _key,const char* _value)
{
	string key = CURLCode::Encode(_key);
	string value = CURLCode::Encode(_value);

	if (_msg.size() != 0)
	{
		_msg += "&";
	}

	_msg += key;
	_msg += "=";
	_msg += value;
}

void PostMsg::pushCmd(const char* _key,int _value)
{
	char str[50];
	sprintf(str,"%d",_value);
	pushCmd(_key,str);
}

void PostMsg::pushCmd(const char* _key,float _value)
{
	char str[50];
	sprintf(str,"%f",_value);
	pushCmd(_key,str);
}