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
		/**
		 * @var
		 */
		std::string text;
		/**
		 * @var
		 */
		std::string url;
		/**
		 * @var
		 */
		LoginUrl::ptr login_url;
		/**
		 * @var
		 */
		std::string callback_data;
		/**
		 * @var
		 */
		std::string switch_inline_query;
		/**
		 * @var
		 */
		std::string switch_inline_query_current_chat;
		/**
		 * @var
		 */
		CallbackGame::ptr callback_game;
		/**
		 * @var
		 */
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
