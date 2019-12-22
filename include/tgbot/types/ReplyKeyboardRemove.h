#ifndef TGBOT_TYPES_REPLYKEYBOARDREMOVE_H
#define TGBOT_TYPES_REPLYKEYBOARDREMOVE_H

#include <rapidjson/document.h>
#include <memory>
#include "tgbot/types/Reply.h"

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct ReplyKeyboardRemove : public Reply
	{
		//pointer of itself
		typedef std::shared_ptr<ReplyKeyboardRemove> ptr;

		//member variables
		bool remove_keyboard;
		bool selective;

		//constructors
		ReplyKeyboardRemove();

		//@param json: json object of ReplyKeyboardRemove
		ReplyKeyboardRemove(const std::string &json);

		//member functions
		/*
		 * @brief parses the itself into its json equivalent
		 * @return return a string which represents a itself
		 */
		std::string parse_to_json() const;
	};
}

#endif
