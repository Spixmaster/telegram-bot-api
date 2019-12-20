#ifndef TGBOT_TYPES_KEYBOARDBUTTON_H
#define TGBOT_TYPES_KEYBOARDBUTTON_H

#include <string>
#include <rapidjson/document.h>
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct KeyboardButton
	{
		//pointer of itself
		typedef std::shared_ptr<KeyboardButton> ptr;

		//member variables
		std::string text;
		bool request_contact = false;
		bool request_location = false;

		//constructors
		KeyboardButton();

		//@param json: json object of KeyboardButton
		KeyboardButton(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
