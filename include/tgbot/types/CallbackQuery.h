#ifndef TYPES_CALLBACKQUERY_H
#define TYPES_CALLBACKQUERY_H

#include <string>
#include "tgbot/types/User.h"
#include "tgbot/types/Message.h"
#include "tgbot/special_tools.h"
#include <memory>

namespace tgbot
{
	struct CallbackQuery
	{
		//pointer of itself
		typedef std::shared_ptr<CallbackQuery> ptr;

		//member variables
		std::string id;
		User::ptr from;
		Message::ptr message;
		std::string inline_message_id;
		std::string chat_instance;
		std::string data;
		std::string game_short_name;

		//constructors
		CallbackQuery();

		//@param json: json object of CallbackQuery
		CallbackQuery(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
