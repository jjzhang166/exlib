#include "HttpConnect.h"
#include "../common/tplib.h"
#include "../file/tpfile.h"
#include "../file/TPLog.h"
#include "../common/CMD.h"

USING_NS_CC;
using namespace std;

string HttpConnect::_url = "http://j.shoujiqipai.com/snake/";
int HttpConnect::_time_out = 15;

HttpConnect::HttpConnect()
{
}

HttpConnect::~HttpConnect()
{
	HttpClient::destroyInstance();
}  

void HttpConnect::setUrl(const char* _url)
{
	HttpConnect::_url = _url;
}

void HttpConnect::setTimeOut(int _time_out)
{
	HttpConnect::_time_out = _time_out;
}

void HttpConnect::sendMsg(const char* _cmd, PostMsg _post_msg)
{
	writeHttpLog(_post_msg.getMsg().c_str());
	string url = _url;
	url += _cmd;
	url += ".ashx";

	HttpClient* httpClient = HttpClient::getInstance();
    auto str = FileUtils::getInstance()->getWritablePath() + "cook.txt";
	httpClient->enableCookies(str.c_str());
	HttpRequest* httpReq = new HttpRequest();

	httpReq->setRequestType(HttpRequest::Type::POST);
	httpReq->setUrl(url.c_str());
	httpReq->setResponseCallback(this,httpresponse_selector(HttpConnect::httpReqFinished));
	httpReq->setRequestData(_post_msg.getMsg().c_str(),strlen(_post_msg.getMsg().c_str()));

	httpReq->setTag(_cmd);
	httpClient->setTimeoutForConnect(HttpConnect::_time_out);
	HttpClient::getInstance()->send(httpReq);
	httpReq->release();
}

void HttpConnect::httpReqFinished(HttpClient* client, HttpResponse* response)
{
	if (!response)
	{
		return;
	}

	if (!response->isSucceed())
	{
		log("Receive Error! %s \n",response->getErrorBuffer());
		writeHttpLog("Receive Error!");
		writeHttpLog(toString(response->getResponseCode()).c_str());
		writeHttpLog(response->getErrorBuffer());
		return ;
	}

	const char* tag = response->getHttpRequest()->getTag();

	if ( isCmd(tag))  
	{  
		std::vector<char> *data = response->getResponseData();  
		int data_length =  data->size();  
		std::string res;  
		for (int i = 0;i<data_length;++i)  
		{  
			res+=(*data)[i];  
		}  
		res+='\0'; 
		
		writeHttpLog(res.c_str());
		log("http:%s",res.c_str());

		Document document;
		document.Parse<0>(res.c_str());

		if (document.HasParseError())
		{
			writeLog("Parse Error");
			writeLog(res.c_str());
			return;
		}

		cmdList()[tag](document);
		log("%s",res.c_str());  
	} 
	else
	{
		writeLog("not found cmd");
		writeLog(tag);
	}
}

HttpConnect* HttpConnect::getInstance()
{
	static HttpConnect instance;
	return &instance;
}

void HttpConnect::sendUrlMsg( const char* url,const char* _cmd, PostMsg _post_msg )
{
	writeHttpLog(_post_msg.getMsg().c_str());

	HttpClient* httpClient = HttpClient::getInstance();
	auto str = FileUtils::getInstance()->getWritablePath() + "cook.txt";
	httpClient->enableCookies(str.c_str());
	HttpRequest* httpReq = new HttpRequest();

	httpReq->setRequestType(HttpRequest::Type::POST);
	httpReq->setUrl(url);
	httpReq->setResponseCallback(this,httpresponse_selector(HttpConnect::httpReqUrlFinished));
	httpReq->setRequestData(_post_msg.getMsg().c_str(),strlen(_post_msg.getMsg().c_str()));

	httpReq->setTag(_cmd);
	httpClient->setTimeoutForConnect(HttpConnect::_time_out);
	HttpClient::getInstance()->send(httpReq);
	httpReq->release();
}

void HttpConnect::httpReqUrlFinished( HttpClient* client, HttpResponse* response )
{
	if (!response)
	{
		return;
	}

	if (!response->isSucceed())
	{
		log("Receive Error! %s \n",response->getErrorBuffer());
		writeHttpLog("Receive Error!");
		writeHttpLog(toString(response->getResponseCode()).c_str());
		writeHttpLog(response->getErrorBuffer());
		return ;
	}

	const char* tag = response->getHttpRequest()->getTag();

	if ( isCmd(tag))  
	{  
		std::vector<char> *data = response->getResponseData();  
		int data_length =  data->size();  
		std::string res;  
		for (int i = 0;i<data_length;++i)  
		{  
			res+=(*data)[i];  
		}  
		res+='\0'; 

		writeHttpLog(res.c_str());
		log("http:%s",res.c_str());

		Document document;
		document.Parse<0>(res.c_str());

		if (document.HasParseError())
		{
			writeLog("Parse Error");
			writeLog(res.c_str());
			return;
		}

		cmdList()[tag](document);
		log("%s",res.c_str());  
	} 
	else
	{
		writeLog("not found cmd");
		writeLog(tag);
	}
}

void sendMsg(const char* _cmd, PostMsg _post_msg)
{
	HttpConnect::getInstance()->sendMsg(_cmd,_post_msg);
}

void sendMsgUrl( const char* url,const char* _cmd, PostMsg _post_msg )
{
	HttpConnect::getInstance()->sendUrlMsg(url,_cmd,_post_msg);
}
