#ifndef _POSTMSG_H_
#define _POSTMSG_H_

#include <string>
using namespace std;

class PostMsg
{
public:
	void pushCmd(const char* _key,const char* _value);
	void pushCmd(const char* _key,int _value);
	void pushCmd(const char* _key,float _value);
	string getMsg();
private:
	string _msg;
};
#endif