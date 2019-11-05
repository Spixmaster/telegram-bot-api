#ifndef TGBOT_HTTP_HTTPRESPONSE_H
#define TGBOT_HTTP_HTTPRESPONSE_H

#include <string>
#include <memory>

//@brief struct that contains some information about the http request

namespace tgbot
{
	struct HttpResponse
	{
		//pointer of itself
		typedef std::shared_ptr<HttpResponse> ptr;

		//member variables
		std::string code;
		std::string txt;
	};
}

#endif
