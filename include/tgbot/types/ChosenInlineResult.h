#ifndef TGBOT_TYPES_CHOSENINLINERESULT_H
#define TGBOT_TYPES_CHOSENINLINERESULT_H

#include <string>
#include "tgbot/types/User.h"
#include "tgbot/types/Location.h"
#include <rapidjson/document.h>
#include "tgbot/SpecialTools.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct ChosenInlineResult
	{
		//pointer of itself
		typedef std::shared_ptr<ChosenInlineResult> ptr;

		//member variables
		std::string result_id;
		User::ptr from;
		Location::ptr location;
		std::string inline_message_id;
		std::string query;

		//constructors
		ChosenInlineResult();

		//@param json: json object of ChosenInlineResult
		ChosenInlineResult(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
