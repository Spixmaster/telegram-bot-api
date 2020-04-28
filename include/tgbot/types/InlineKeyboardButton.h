#ifndef TGBOT_TYPES_INLINEKEYBOARDBUTTON_H
#define TGBOT_TYPES_INLINEKEYBOARDBUTTON_H

#include <string>
#include "tgbot/types/LoginUrl.h"
#include "tgbot/types/CallbackGame.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineKeyboardButton
	 */
	struct InlineKeyboardButton
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineKeyboardButton> ptr;

		//Member variables
		std::string text;
		std::string url;
		LoginUrl::ptr login_url;
		std::string callback_data;
		std::string switch_inline_query;
		std::string switch_inline_query_current_chat;
		CallbackGame::ptr callback_game;
		bool pay;

		//Constructors
		InlineKeyboardButton();

		//@param json: json object of InlineKeyboardButton
		InlineKeyboardButton(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
