#pragma once
#include "cocos2d.h"
#include <string>
#include <map>

USING_NS_CC;
using namespace std;

typedef map<string,map<string,string>> CSV;
CSV readCSV(string filename,bool encrypt = false);
void writeCSV(string filename,CSV csv,bool encrypt = false);
vector<string> explode(string str,string separator);
string replace( const string& inStr, const char* pSrc, const char* pReplace);