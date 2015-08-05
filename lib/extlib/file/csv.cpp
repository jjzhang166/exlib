#include "csv.h"
#include "../crypt/OBEncrytionUtil.h"
#include "tpfile.h"


CSV readCSV( string filename ,bool encrypt)
{
	CSV ret;
	ssize_t nSize = 0;
	char pKey[5] = {'1','9','8','1','6'};
	char* pBuffer = (char*)CCFileUtils::getInstance()->getFileData(filename, "rb", &nSize);
	string buff;
	if (encrypt)
	{
		Makecode(pBuffer,pKey,nSize);
		buff.assign(pBuffer,nSize);
	}	
	else
	{
		buff.assign(pBuffer);
	}
	

	string::size_type pos = 0;
	string::size_type lastPos = pos;

	string searchString("\r\n");
	vector<string> strVec;
	string key;

	while((pos = buff.find(searchString, pos)) != string::npos) {
		buff.replace(pos, searchString.size(), "");
		string tempStr = buff.substr(lastPos,pos-lastPos);
		if (lastPos == 0)
		{
			key = tempStr;
		}
		else
		{
			strVec.push_back(tempStr);
		}
		
		lastPos = pos;
	}

	vector<string> keyVec = explode(key,",");

	for (auto value:strVec)
	{
		vector<string> valueVec = explode(value,",");
		for (int i = 1; i < keyVec.size(); i++)
		{
			ret[valueVec[0]][keyVec[i]] = valueVec[i];
		}
	}

	return ret;
}

void writeCSV( string filename,CSV csv,bool encrypt /*= false*/ )
{
	string str = "id";
	for (auto id : csv)
	{
		for (auto i : id.second)
		{
			str += ",";
			str += i.first;
		}
		break;
	}

	str += "\r\n";

	for (int j = 0; j < csv.size(); j++)
	{
		int k = 0;
		for (auto id : csv)
		{
			if (k == j)
			{
				str += id.first;
				for (auto i : id.second)
				{
					str += ",";
					str += i.second;
				}
				str += "\r\n";
			}
		}
		k++;
	}

	writeFile(filename,str,encrypt);
}

vector<string> explode( string str,string separator )
{
	vector<string> ret;
	string::size_type pos = 0;
	string::size_type lastPos = pos;

	while((pos = str.find(separator, pos)) != string::npos) {
		str.replace(pos, separator.size(), "");
		string tempStr = str.substr(lastPos,pos-lastPos);
		ret.push_back(tempStr);
		lastPos = pos;
	}

	string tempStr = str.substr(lastPos,pos-lastPos);
	ret.push_back(tempStr);
	return ret;
}

string replace( const string& inStr, const char* pSrc, const char* pReplace )
{
	string strSrc = inStr;
	string::size_type pos=0;       
	string::size_type srclen = strlen( pSrc );        
	string::size_type dstlen = strlen( pReplace );        
	while( (pos=strSrc.find(pSrc, pos)) != string::npos)
	{                
		strSrc.replace(pos, srclen, pReplace);                
		pos += dstlen;        
	}
	return strSrc;
}
