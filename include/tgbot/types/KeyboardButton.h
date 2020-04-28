#ifndef TGBOT_TYPES_KEYBOARDBUTTON_H
#define TGBOT_TYPES_KEYBOARDBUTTON_H

#include <string>
#include <rapidjson/document.h>
#include <memory>
#include "tgbot/types/KeyboardButtonPollType.h"

namespace tgbot
{
	/**
	 * @struct KeyboardButton
	 */
	struct KeyboardButton
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<KeyboardButton> ptr;

		//Member variables
		/**
		 * @var
		 */
		std::string text;
		/**
		 * @var
		 */
		bool request_contact = false;
		/**
		 * @var
		 */
		bool request_location = false;
		/**
		 * @var
		 */
		KeyboardButtonPollType::ptr request_poll;

		//Constructors
		KeyboardButton();

		//@param json: json object of KeyboardButton
		KeyboardButton(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
