#ifndef TGBOT_TYPES_KEYBOARDBUTTONPOLLTYPE_H
#define TGBOT_TYPES_KEYBOARDBUTTONPOLLTYPE_H

#include <string>
#include "rapidjson/document.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct KeyboardButtonPollType
	 */
	struct KeyboardButtonPollType
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<KeyboardButtonPollType> ptr;

		//Member variables
		std::string type;

		//Constructors
		KeyboardButtonPollType();

		//@param json: json object of KeyboardButtonPollType
		KeyboardButtonPollType(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
