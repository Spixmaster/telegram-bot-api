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
		std::string id;
		User::ptr from;
		Message::ptr message;
		std::string inline_message_id;
		std::string chat_instance;
		std::string data;
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
