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

	//��ʼ�������б�
	void init();

	//�жϸ������Ƿ����
	bool isCMD(const char* _cmd);

	//��ȡ�����б�
	map<string, function<void(Document& _str)>> getCmd();

	//�����߼�ʵ��
	cmdLogic* _cmdLogic;

	//���������
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