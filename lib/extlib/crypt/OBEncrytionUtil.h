#ifndef OB_ENCRYTION_UTIL
#define OB_ENCRYTION_UTIL

#include<iostream>
#include<ctime>
#include "cocos2d.h"

using namespace std;
USING_NS_CC;

//单个字符异或运算
void Makecode(char *pstr,char *pkey,ssize_t len);

//class Code 
//{ 
//public: 
//	static string Encode(string src,int key = 5) 
//	{ 
//		string des; 
//		for (int i = 0; i<src.size(); i++) 
//		{ 
//			src[i] += key;
//			des+=~src[i];
//		} 
//		return des; 
//	}
//	static string Decode(string src,int key = 5) 
//	{ 
//		string des; 
//		for (int i = 0; i<src.size(); i++) 
//		{ 
//			char temp = ~src[i];
//			temp -= key;
//			des+=temp;
//		}
//		return des; 
//	} 
//}; 

class EncrytionUtil 
{
public:
	static int Encryt(std::string& stream, const char* secret = "tuansbookgame")
	{
		return Encryt(stream, 0,  stream.length()-1, secret);
	}

	static int Decrpt(std::string& stream, const char* secret = "tuansbookgame")
	{
		return Decrpt(stream, 0, stream.length()-1, secret);
	}

	static int Encryt(std::string& stream, int begin, int end, const char* secret)
	{
		return XORM(stream, begin, end, secret);
	}

	static int Decrpt(std::string& stream, int begin, int end, const char* secret)
	{
		return XORM(stream, begin, end, secret);
	}

private:
	static int XORM(std::string& stream, int begin, int end, const char* secret)
	{
		if (begin<0 || end>=stream.length() || begin>end || strlen(secret) == 0)
		{
			return -1;
		}

		int keyLength = strlen(secret);
		int j(0);
		for (int i=begin; i<=end; i++)
		{
			if (j>=keyLength)
			{
				j = 0;
			} 
			stream[i] = stream[i] ^ secret[j];
			if(stream[i] == '\0')
			{
				stream[i] = secret[j];
			}
			j++;
		}

		return 0;
	}
};

class UserEncrytionUtil
{
public:
	static void setStringForKey(const char* key, const char* value,const char* secret = "tuansbookgame")
	{
		UserDefault* encoder = UserDefault::getInstance();
		if (encoder)
		{
			std::string keyString = key;
			//    EncrytionUtil::Encryt(keyString,secret);

			std::string valueString = value;
			EncrytionUtil::Encryt(valueString,secret);

			// CCLOG("before Encrytion: %s >> after Encrytion: %s",value,valueString.c_str());
			encoder->setStringForKey(keyString.c_str(), valueString);
			encoder->flush();
		}
	}

	static void setIntegerForKey(const char* key, int value,const char* secret = "tuansbookgame")
	{
		char valueString[64] = {0};
		sprintf(valueString, "%d",value);
		setStringForKey(key,valueString,secret);
	}

	static std::string getStringForKey(const char* key, const char* secret = "tuansbookgame")
	{
		UserDefault* decoder = UserDefault::getInstance();
		if (decoder)
		{
			std::string keyString = key;
			//   EncrytionUtil::Encryt(keyString,secret);

			std::string valueString = decoder->getStringForKey(keyString.c_str());
			//    CCLOG("get string from XML: %s", valueString.c_str());
			EncrytionUtil::Decrpt(valueString,secret);
			//  CCLOG("after Decrption : %s",valueString.c_str());
			return valueString;
		}
		return "";
	}

	static int getIntegerForKey(const char* key,const char* secret = "tuansbookgame")
	{
		return  atoi(getStringForKey(key,secret).c_str());
	}
};

#endif // !OB_ENCRYTION_UTIL

