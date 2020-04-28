#ifndef TGBOT_TYPES_MESSAGEENTITY_H
#define TGBOT_TYPES_MESSAGEENTITY_H

#include <string>
#include <memory>
#include "tgbot/types/User.h"

namespace tgbot
{
	/**
	 * @struct MessageEntity
	 */
	struct MessageEntity
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<MessageEntity> ptr;

		//Member variables
		std::string type;
		int offset = -1;
		int length = -1;
		std::string url;
		User::ptr user;
		std::string language;

		//Constructors
		MessageEntity();

		//@param json: json object of MessageEntity
		MessageEntity(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
