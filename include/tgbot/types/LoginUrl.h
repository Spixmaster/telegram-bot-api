#ifndef TGBOT_TYPES_LOGINURL_H
#define TGBOT_TYPES_LOGINURL_H

#include <string>
#include <memory>

namespace tgbot
{
	struct LoginUrl
	{
		//pointer of itself
		typedef std::shared_ptr<LoginUrl> ptr;

		//member variables
		std::string url;
		std::string forward_text;
		std::string bot_username;
		bool request_write_access;

		//constructors
		LoginUrl();

		//@param json: json object of LoginUrl
		LoginUrl(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
