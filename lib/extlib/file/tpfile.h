#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

bool isFile(string fileName);
void writeFile(string fileName,string context,bool encrypt = false);
void writeFileA(string fileName,string context);
string readFile(string fileName,bool encrypt = false);