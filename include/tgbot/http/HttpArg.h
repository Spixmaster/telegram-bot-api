#ifndef TGBOT_HTTPARG_H
#define TGBOT_HTTPARG_H

#include <string>
#include <memory>
#include <boost/lexical_cast.hpp>
#include <variant>
#include "tgbot/http/InputFile.h"

namespace tgbot
{
	struct HttpArg
	{
		//pointer of itself
		typedef std::shared_ptr<HttpArg> ptr;

		//member variables
		std::string m_key;
		std::variant<long long, std::string, InputFile::ptr> m_value;

		//constructors
		/*
		 * @param key: key of the post data
		 * @param value: value of the post data
		 */
		HttpArg(const std::string &key, const std::variant<long long, std::string, InputFile::ptr> &value);
	};
}

#endif
