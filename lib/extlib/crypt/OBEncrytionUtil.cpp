#include "OBEncrytionUtil.h"

char MakecodeChar(char c,char key){
	return c^=key;
}

//����||���ܺ���
//pstr:��Ҫ����||���ܵ�����
//pkey����Կ���ݣ�5λ�����磺char pKey[5] = {'1','9','8','1','6'};
//len��pstr����
void Makecode(char *pstr,char *pkey,ssize_t len){
	for(int i=0;i<len;i++)
		*(pstr+i)=MakecodeChar(*(pstr+i),pkey[i%5]);
}