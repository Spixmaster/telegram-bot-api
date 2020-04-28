#ifndef TGBOT_TYPES_REPLYKEYBOARDMARKUP_H
#define TGBOT_TYPES_REPLYKEYBOARDMARKUP_H

#include "tgbot/types/KeyboardButton.h"
#include <vector>
#include <memory>
#include "tgbot/types/Reply.h"

namespace tgbot
{
	/**
	 * @struct ReplyKeyboardMarkup
	 */
	struct ReplyKeyboardMarkup : public Reply
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<ReplyKeyboardMarkup> ptr;

		//Member variables
		/**
		 * @var
		 */
		std::vector<std::vector<KeyboardButton::ptr>> keyboard;
		/**
		 * @var
		 */
		bool resize_keyboard = false;
		/**
		 * @var
		 */
		bool one_time_keyboard = false;
		/**
		 * @var
		 */
		bool selective = false;

		//Constructors
		ReplyKeyboardMarkup();

		//@param json: json object of ReplyKeyboardMarkup
		ReplyKeyboardMarkup(const std::string &json);

		//@param keyboard: forms the ReplyKeyboardMarkup
		ReplyKeyboardMarkup(const std::vector<std::vector<KeyboardButton::ptr>> &keyboard);

		//Member functions
		/*
		 * @brief parses itself into json equivalent
		 * @return json object of the itself as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
