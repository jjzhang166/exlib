#ifndef __CURLCode_H__
#define __CURLCode_H__
#include "cocos2d.h"

using namespace std;

class CURLCode 
{
public:
	CURLCode(void);
	~CURLCode(void);
	static string Encode(const char* lpszData);/*¼ÓÃÜ*/
	static string Decode(string inTmp);/*½âÃÜ*/
private:
	inline static unsigned char toHex(const unsigned char &x){ return x > 9 ? x + 55: x + 48; }
	inline static unsigned char fromHex(const unsigned char &x){ return x > 64 ? x - 55 : x - 48; }
};
#endif
