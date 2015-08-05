#pragma once
#include <string>
#include <sstream>

using namespace std;
template<class T>
string toString(T _int)
{
	string tstr;
	stringstream tstream;
	tstream << _int;
	tstr = tstream.str();
	return tstr;
}

int toInt(string _string);
int random(int i);