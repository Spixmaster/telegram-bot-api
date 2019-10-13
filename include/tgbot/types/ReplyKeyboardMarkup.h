#ifndef TGBOT_TYPES_REPLYKEYBOARDMARKUP_H
#define TGBOT_TYPES_REPLYKEYBOARDMARKUP_H

#include "tgbot/types/KeyboardButton.h"
#include <vector>
#include "tgbot/SpecialTools.h"
#include <memory>
#include "tgbot/types/Reply.h"

namespace tgbot
{
	struct ReplyKeyboardMarkup : public Reply
	{
		//pointer of itself
		typedef std::shared_ptr<ReplyKeyboardMarkup> ptr;

		//member variables
		std::vector<std::vector<KeyboardButton::ptr>> keyboard;
		bool resize_keyboard = false;
		bool one_time_keyboard = false;
		bool selective = false;

		//constructors
		ReplyKeyboardMarkup();

		//@param json: json object of ReplyKeyboardMarkup
		ReplyKeyboardMarkup(const std::string &json);

		//@param keyboard: forms the ReplyKeyboardMarkup
		ReplyKeyboardMarkup(const std::vector<std::vector<KeyboardButton::ptr>> &keyboard);

		//member functions

		/*
		 * @brief parses itself into json equivalent
		 * @return json object of the itself as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
