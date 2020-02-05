#ifndef TGBOT_TYPES_KEYBOARDBUTTONPOLLTYPE_H
#define TGBOT_TYPES_KEYBOARDBUTTONPOLLTYPE_H

#include <string>
#include "rapidjson/document.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct KeyboardButtonPollType
	{
		//pointer of itself
		typedef std::shared_ptr<KeyboardButtonPollType> ptr;

		//member variables
		std::string type;

		//constructors
		KeyboardButtonPollType();

		//@param json: json object of KeyboardButtonPollType
		KeyboardButtonPollType(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
