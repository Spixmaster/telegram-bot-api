#ifndef TGBOT_TYPES_MESSAGEENTITY_H
#define TGBOT_TYPES_MESSAGEENTITY_H

#include <string>
#include <memory>
#include "tgbot/types/User.h"

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct MessageEntity
	{
		//pointer of itself
		typedef std::shared_ptr<MessageEntity> ptr;

		//member variables
		std::string type;
		int offset = -1;
		int length = -1;
		std::string url;
		User::ptr user;
		std::string language;

		//constructors
		MessageEntity();

		//@param json: json object of MessageEntity
		MessageEntity(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
