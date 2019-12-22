#ifndef TGBOT_TYPES_INLINEQUERY_H
#define TGBOT_TYPES_INLINEQUERY_H

#include <string>
#include "tgbot/types/User.h"
#include "tgbot/types/Location.h"
#include <rapidjson/document.h>
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct InlineQuery
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQuery> ptr;

		//member variables
		std::string id;
		User::ptr from;
		Location::ptr location;
		std::string query;
		std::string offset;

		//constructors
		InlineQuery();

		//@param json: json object of InlineQuery
		InlineQuery(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
