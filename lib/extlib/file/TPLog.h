#pragma once
#include <iostream>
#include "cocos2d.h"
#include <map>
#include <string>

USING_NS_CC;
using namespace std;

//日志记录类
class Log
{
public:
	void writeLog(const char* _error_msg);
	void writeLog(int _error_msg);
	void writeHttpLog(const char* _error_msg);
	void writeHttpLog(int _error_msg);
	static Log* getInstance();
private:
	string kLogWrap;
	Log();
	~Log();
	static Log* _this;
};

void writeLog(const char* _error_msg);
void writeLog(Point point);
void writeLog(map<int ,map<int,string>>);
void writeHttpLog(const char* _error_msg);