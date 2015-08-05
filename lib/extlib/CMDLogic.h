#ifndef _CMD_LOGIC_H_
#define _CMD_LOGIC_H_
#include "external/json/document.h"  
#include "external/json/stringbuffer.h"
#include "external/json/writer.h"

using namespace rapidjson;

class cmdLogic 
{
public:
	enum timeState
	{
		normalLevel,
		stealEnd,
		outEnd,
		returnEnd
	};

	void registerCallback();
	//ªÒµ√≈≈––∞Ò
	int getRank(Document& data);

	cmdLogic();
	~cmdLogic();
private:
};
#endif