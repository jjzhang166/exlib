#include "OBEncrytionUtil.h"

char MakecodeChar(char c,char key){
	return c^=key;
}

//加密||解密函数
//pstr:需要加密||解密的数据
//pkey：密钥数据（5位）例如：char pKey[5] = {'1','9','8','1','6'};
//len：pstr长度
void Makecode(char *pstr,char *pkey,ssize_t len){
	for(int i=0;i<len;i++)
		*(pstr+i)=MakecodeChar(*(pstr+i),pkey[i%5]);
}