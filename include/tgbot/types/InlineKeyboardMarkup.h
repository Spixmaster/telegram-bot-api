#ifndef TYPES_INLINEKEYBOARDMARKUP_H
#define TYPES_INLINEKEYBOARDMARKUP_H

#include "tgbot/types/InlineKeyboardButton.h"
#include <vector>
#include <memory>
#include "tgbot/types/Reply.h"

namespace tgbot
{
	struct InlineKeyboardMarkup : public Reply
	{
		//pointer of itself
		typedef std::shared_ptr<InlineKeyboardMarkup> ptr;

		//member variables
		std::vector<std::vector<InlineKeyboardButton::ptr>> inline_keyboard;

		//constructors
		InlineKeyboardMarkup();

		//@param json: json object of InlineKeyboardMarkup
		InlineKeyboardMarkup(const std::string &json);

		//@param vector of vector(s) which contains InlineKeyboardButton
		InlineKeyboardMarkup(const std::vector<std::vector<InlineKeyboardButton::ptr>> &keyboard);

		//member functions

		/*
		 * @brief parses an itself to a json object
		 * @return json object of itself as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
