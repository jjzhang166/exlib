#include "tpfile.h"
#include "TPLog.h"
#include "../crypt/OBEncrytionUtil.h"

bool isFile( string fileName )
{
	string filePath = FileUtils::getInstance()->getWritablePath();
	filePath.append(fileName);

	fstream file;
	file.open(filePath,ios::in);
	if (file == NULL)
	{
		return false;
	}

	file.close();
	return true;
}

void writeFile( string fileName,string context,bool encrypt)
{
	string filePath = FileUtils::getInstance()->getWritablePath();
	filePath.append(fileName);

	char* buffer = const_cast<char*>(context.c_str());
	long size = context.size();

	if (encrypt)
	{
		char pKey[5] = {'1','9','8','8','8'};
		Makecode((char*)buffer,pKey,size);
	}

	FILE *fp = fopen(filePath.c_str(), "wb+");
	if (fp == nullptr)
	{
		writeLog("save error");
		return;
	}

	fwrite(buffer,size,1,fp);

	fclose(fp);
}

void writeFileA( string fileName,string context )
{
	string filePath = FileUtils::getInstance()->getWritablePath();
	filePath.append(fileName);

	fstream file;
	file.open(filePath,ios::out | ios::app);
	file << context;
	file.close();
}

std::string readFile( string fileName ,bool encrypt)
{
	string filePath = FileUtils::getInstance()->getWritablePath();
	filePath.append(fileName);

	unsigned char * buffer = nullptr;
	long size = 0;

		// read the file from hardware
	FILE *fp = fopen(filePath.c_str(), "rb");
	if (fp == nullptr)
	{
		CCLOG("%s", "fp == nullptr");
		return "";
	}

	fseek(fp,0,SEEK_END);
	size = ftell(fp);
	fseek(fp,0,SEEK_SET);
	buffer = (unsigned char*)malloc(size);
	size = fread(buffer,sizeof(unsigned char), size,fp);
	fclose(fp);

	if (! buffer)
	{
		std::string msg = "Get data from file(";
		msg.append(filePath).append(") failed!");
		CCLOG("%s", msg.c_str());
	}

	if (encrypt)
	{
		char pKey[5] = {'1','9','8','8','8'};
		Makecode((char*)buffer,pKey,size);
	}
	
	string context = (char*)buffer;
	free(buffer);

	return context;
}
