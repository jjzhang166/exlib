#ifndef _HTTP_CONNECT_H_
#define _HTTP_CONNECT_H_

#include <cocos2d.h>
#include "extensions/cocos-ext.h"
#include "network/HttpClient.h"
#include "PostMsg.h"

USING_NS_CC;
using namespace network;
using namespace std;

#define HTTP_REGISTER "http://124.128.87.12:809/Service/Register"
#define HTTP_LOGIN "http://124.128.87.12:809/Service/LoginIn"

class HttpConnect: public Layer  
{  
public:
	static HttpConnect* getInstance();

	//设置url
	static void setUrl(const char* _url);

	//设置超时时间
	static void setTimeOut(int _time_out);

	//发送信息
	void sendMsg(const char* _cmd, PostMsg _post_msg);
	void sendUrlMsg(const char* url,const char* _cmd, PostMsg _post_msg);

	//接收信息，回调函数
	void httpReqFinished(HttpClient* client, HttpResponse* response);
	void httpReqUrlFinished(HttpClient* client, HttpResponse* response);
private:
	HttpConnect();
	virtual ~HttpConnect();
	static string _url;
	static int _time_out;
};

void sendMsg(const char* _cmd, PostMsg _post_msg);
void sendMsgUrl(const char* url,const char* _cmd, PostMsg _post_msg);
#endif
