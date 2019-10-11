#ifndef HTTP_HTTPCLIENT_H
#define HTTP_HTTPCLIENT_H

#include <string>
#include <memory>
#include "tgbot/http/HttpArg.h"

namespace tgbot
{
	class HttpClient
	{
	public:
		//pointer of itself
		typedef std::shared_ptr<HttpClient> ptr;

	private:
		//member variables
		std::string m_url;
		std::vector<HttpArg> m_http_args;

	public:
		//constructors

		//@param url: to which server the request shall be sent
		HttpClient(const std::string &url);

		/*
		 * @param url: to which server the request shall be sent
		 * @param http_args: http args which are sent with the request
		 */
		HttpClient(const std::string &url, const std::vector<HttpArg> &http_args);

		//member functions

		/*
		 * @brief makes a simple get request
		 * @return the server response
		 */
		std::string send_get_req();

		/*
		 * @brief makes a post request
		 * @return the server response
		 */
		std::string send_post_req();
	};
}

#endif
