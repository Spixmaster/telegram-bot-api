#ifndef TGBOT_TYPES_INPUTLOCATIONMESSAGECONTENT_H
#define TGBOT_TYPES_INPUTLOCATIONMESSAGECONTENT_H

#include "tgbot/types/InputMessageContent.h"
#include <string>
#include <memory>

namespace tgbot
{
	struct InputLocationMessageContent : public InputMessageContent
	{
		//pointer of itself
		typedef std::shared_ptr<InputLocationMessageContent> ptr;

		//member variables
		float latitude = -1;
		float longitude = -1;
		int live_period = -1;

		//constructors
		InputLocationMessageContent();

		//@param json: json object of InputLocationMessageContent
		InputLocationMessageContent(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
