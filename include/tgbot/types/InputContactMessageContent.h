#ifndef TGBOT_TYPES_INPUTCONTACTMESSAGECONTENT_H
#define TGBOT_TYPES_INPUTCONTACTMESSAGECONTENT_H

#include <string>
#include "tgbot/types/InputMessageContent.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InputContactMessageContent
	 */
	struct InputContactMessageContent : public InputMessageContent
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InputContactMessageContent> ptr;

		//Member variables
		std::string phone_number;
		std::string first_name;
		std::string last_name;
		std::string vcard;

		//Constructors
		InputContactMessageContent();

		//@param json: json object of InputContactMessageContent
		InputContactMessageContent(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
