#include "TPLog.h"
#include "stdio.h"
#include "time.h"
#include <iostream>
#include <cocos2d.h>
#include "../common/tplib.h"
#include "tpfile.h"

USING_NS_CC;
using namespace std;

Log* Log::_this = NULL;

Log::Log()
{
	kLogWrap = "\r\n";
}

Log::~Log()
{

}

Log* Log::getInstance()
{
	if (_this == NULL)
	{
		_this = new Log();
	}

	return _this;
}

void Log::writeLog(const char* _error_msg)
{
	time_t t_time;
	t_time = time(NULL);

	tm* ptr;
	ptr = localtime(&t_time);

	char fstr[80] = {0};
	strftime(fstr,sizeof(fstr),"%Y-%m-%d",ptr);

	char tstr[80] = {0};
	strftime(tstr,sizeof(tstr),"%Y-%m-%d %H:%M:%S",ptr);

	string file_path = FileUtils::getInstance()->getWritablePath();
	file_path.append(fstr);
	FILE* file;
	file = fopen(file_path.c_str(),"a+");

	if (!file)
	{
		printf("open file error !!!");
		return;
	}

	fwrite(tstr,1,strlen(tstr),file);
	fwrite(kLogWrap.c_str(),1,kLogWrap.size(),file);
	fwrite(_error_msg, 1, strlen(_error_msg), file); 
	fwrite(kLogWrap.c_str(),1,kLogWrap.size(),file);
	fclose(file);
}

void Log::writeLog(int _error_msg)
{
	time_t t_time;
	t_time = time(NULL);

	tm* ptr;
	ptr = localtime(&t_time);

	char fstr[80] = {0};
	strftime(fstr,sizeof(fstr),"%Y-%m-%d",ptr);

	char tstr[80] = {0};
	strftime(tstr,sizeof(tstr),"%Y-%m-%d %H:%M:%S",ptr);

	string file_path = FileUtils::getInstance()->getWritablePath();
	file_path.append(fstr);
	FILE* file;
	file = fopen(file_path.c_str(),"a+");

	if (!file)
	{
		printf("open file error !!!");
		return;
	}

	char error_str[50] = {0}; 
	sprintf(error_str,"%d",_error_msg);
//	_itoa(_error_msg,error_str,10);

	fwrite(tstr,1,strlen(tstr),file);
	fwrite(kLogWrap.c_str(),1,kLogWrap.size(),file);
	fwrite(error_str, 1, strlen(error_str), file); 
	fwrite(kLogWrap.c_str(),1,kLogWrap.size(),file);
	fclose(file);
}

void Log::writeHttpLog(const char* _error_msg)
{
	
	time_t t_time;
	t_time = time(NULL);

	tm* ptr;
	ptr = localtime(&t_time);

	char fstr[80] = {0};
	strftime(fstr,sizeof(fstr),"%Y-%m-%dhttp",ptr);

	char tstr[80] = {0};
	strftime(tstr,sizeof(tstr),"%Y-%m-%d %H:%M:%S",ptr);

	string file_path = FileUtils::getInstance()->getWritablePath();
	file_path.append(fstr);
	FILE* file;
	file = fopen(file_path.c_str(),"a+");

	if (!file)
	{
		printf("open file error !!!");
		return;
	}

	fwrite(tstr,1,strlen(tstr),file);
	fwrite(kLogWrap.c_str(),1,kLogWrap.size(),file);
	fwrite(_error_msg, 1, strlen(_error_msg), file); 
	fwrite(kLogWrap.c_str(),1,kLogWrap.size(),file);
	fclose(file);
	
}

void Log::writeHttpLog(int _error_msg)
{
	/*
	time_t t_time;
	t_time = time(NULL);

	tm* ptr;
	ptr = localtime(&t_time);

	char fstr[80] = {0};
	strftime(fstr,sizeof(fstr),"%Y-%m-%dhttp",ptr);

	char tstr[80] = {0};
	strftime(tstr,sizeof(tstr),"%Y-%m-%d %H:%M:%S",ptr);

	string file_path = FileUtils::getInstance()->getWritablePath();
	file_path.append(fstr);
	FILE* file;
	file = fopen(file_path.c_str(),"a+");

	if (!file)
	{
		printf("open file error !!!");
		return;
	}

	char error_str[50] = {0}; 
	sprintf(error_str,"%d",_error_msg);
//	_itoa(_error_msg,error_str,10);

	fwrite(tstr,1,strlen(tstr),file);
	fwrite(kLogWrap.c_str(),1,kLogWrap.size(),file);
	fwrite(error_str, 1, strlen(error_str), file); 
	fwrite(kLogWrap.c_str(),1,kLogWrap.size(),file);
	fclose(file);
	*/
}

void writeLog( const char* _error_msg )
{
//	CCLOG(_error_msg);
	Log::getInstance()->writeLog(_error_msg);
}

void writeLog( Point point )
{
	string str = "x:" + toString(point.x) + ",y:" + toString(point.y);
	writeLog(str.c_str());
}

void writeLog( map<int ,map<int,string>> map)
{
	/*
	string context;
	time_t t_time;
	t_time = time(NULL);

	tm* ptr;
	ptr = localtime(&t_time);

	char fstr[80] = {0};
	strftime(fstr,sizeof(fstr),"%Y-%m-%dmaplog",ptr);

	char tstr[80] = {0};
	strftime(tstr,sizeof(tstr),"%Y-%m-%d %H:%M:%S",ptr);

	writeFileA(fstr,tstr);
	writeFileA(fstr,"------------------------\r\n");
	for (int y = 20; y >= 0; y --)
	{
		for (int x = 0; x < 15; x++ )
		{
			context += map[x][y] + "\t";
		}
		context += "\r\n";
	}

	writeFileA(fstr,context);
	writeFileA(fstr,"------------------------\r\n");
	*/
}

void writeHttpLog(const char* _error_msg)
{
	Log::getInstance()->writeHttpLog(_error_msg);
}