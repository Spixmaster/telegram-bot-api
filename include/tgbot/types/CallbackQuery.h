#ifndef TGBOT_TYPES_CALLBACKQUERY_H
#define TGBOT_TYPES_CALLBACKQUERY_H

#include <string>
#include "tgbot/types/User.h"
#include "tgbot/types/Message.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct CallbackQuery
	 */
	struct CallbackQuery
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<CallbackQuery> ptr;

		//Member variables
		/**
		 * @var
		 */
		std::string id;
		/**
		 * @var
		 */
		User::ptr from;
		/**
		 * @var
		 */
		Message::ptr message;
		/**
		 * @var
		 */
		std::string inline_message_id;
		/**
		 * @var
		 */
		std::string chat_instance;
		/**
		 * @var
		 */
		std::string data;
		/**
		 * @var
		 */
		std::string game_short_name;

		//Constructors
		CallbackQuery();

		//@param json: json object of CallbackQuery
		CallbackQuery(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
