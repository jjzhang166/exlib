#include "CMD.h"
#include "tplib.h"
#include <vector>
#include <string>
#include "../file/TPLog.h"

using namespace std;

CMD* CMD::_this = NULL;

/////
//cmd
/////
CMD::CMD()
{
	_cmdLogic = new cmdLogic();
}

CMD::~CMD()
{
	delete _cmdLogic;
}

CMD* CMD::getInstance()
{
	if (_this == NULL)
	{
		_this = new CMD();
		
		_this->init();
	}

	return _this;
}

void CMD::init()
{
	_cmd["test"] = [](Document& arr){writeLog("test");};
	_cmd["register"] = [](Document& arr){
		if (CMD::_this->isError(arr))
		{
			return;
		}

		CMD::_this->_cmdLogic->getRank(arr);
	};
}

bool CMD::isCMD(const char* _cmd)
{
	if (this->_cmd.find(_cmd) == this->_cmd.end())
	{
		return false;
	}

	return true;
}


map<string, function<void(Document& _str)>> CMD::getCmd()
{
	return _cmd;
}

bool CMD::isError( Document& document )
{
	rapidjson::Value& value = document["code"];
	if (value.GetString() != "0")
	{
		return true;
	}

// 	if (document.HasMember("error"))
// 	{
// 		return true;
// 	}

	return false;
}

map<string,function<void(Document& _str)>> cmdList()
{
	return CMD::getInstance()->getCmd();
}

bool isCmd(const char* _cmd)
{
	return CMD::getInstance()->isCMD(_cmd);
}
