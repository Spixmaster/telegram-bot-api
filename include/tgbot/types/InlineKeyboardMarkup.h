#ifndef TGBOT_TYPES_INLINEKEYBOARDMARKUP_H
#define TGBOT_TYPES_INLINEKEYBOARDMARKUP_H

#include "tgbot/types/InlineKeyboardButton.h"
#include <vector>
#include <memory>
#include "tgbot/types/Reply.h"

namespace tgbot
{
	/**
	 * @struct InlineKeyboardMarkup
	 */
	struct InlineKeyboardMarkup : public Reply
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineKeyboardMarkup> ptr;

		//Member variables
		std::vector<std::vector<InlineKeyboardButton::ptr>> inline_keyboard;

		//Constructors
		InlineKeyboardMarkup();

		//@param json: json object of InlineKeyboardMarkup
		InlineKeyboardMarkup(const std::string &json);

		//@param vector of vector(s) which contains InlineKeyboardButton
		InlineKeyboardMarkup(const std::vector<std::vector<InlineKeyboardButton::ptr>> &keyboard);

		//Member functions
		/*
		 * @brief parses an itself to a json object
		 * @return json object of itself as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
