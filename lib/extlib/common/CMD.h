#ifndef _CMD_H_
#define _CMD_H_
#include <map>
#include <vector>
#include <functional>
#include <string>
#include "../CMDLogic.h"

using namespace std;

class CMD
{
public:
	static CMD* getInstance();

	//初始化命令列表
	void init();

	//判断该命令是否存在
	bool isCMD(const char* _cmd);

	//获取命令列表
	map<string, function<void(Document& _str)>> getCmd();

	//命令逻辑实现
	cmdLogic* _cmdLogic;

	//重置命令函数
	void setCmd(const string& str,function<void(Document& _str)> fun) { _cmd[str] = fun; }
private:
	bool isError(Document& document);
	map<string, function<void(Document& _str)>> _cmd;
	static CMD* _this;
	
	CMD();
	~CMD();
};

map<string,function<void(Document& _str)>> cmdList();
bool isCmd(const char* _cmd);

#endif