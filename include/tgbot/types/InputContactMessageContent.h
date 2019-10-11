#ifndef TGBOT_TYPES_INPUTCONTACTMESSAGECONTENT_H
#define TGBOT_TYPES_INPUTCONTACTMESSAGECONTENT_H

#include <string>
#include "tgbot/types/InputMessageContent.h"
#include <memory>

namespace tgbot
{
	struct InputContactMessageContent : public InputMessageContent
	{
		//pointer of itself
		typedef std::shared_ptr<InputContactMessageContent> ptr;

		//member variables
		std::string phone_number;
		std::string first_name;
		std::string last_name;
		std::string vcard;

		//constructors
		InputContactMessageContent();

		//@param json: json object of InputContactMessageContent
		InputContactMessageContent(const std::string &json);
	};
}

#endif
