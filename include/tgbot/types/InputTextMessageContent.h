#ifndef TGBOT_INCLUDE_TYPES_INPUTTEXTMESSAGECONTENT_H_
#define TGBOT_INCLUDE_TYPES_INPUTTEXTMESSAGECONTENT_H_

#include <string>
#include "InputMessageContent.h"
#include "rapidjson/document.h"
#include <memory>

namespace tgbot
{
	struct InputTextMessageContent : public InputMessageContent
	{
		//pointer of itself
		typedef std::shared_ptr<InputTextMessageContent> ptr;

		//member variables
		std::string message_text;
		std::string parse_mode;
		bool disable_web_page_preview;

		//constructors
		InputTextMessageContent();

		//@param json: json object of InputTextMessageContent
		InputTextMessageContent(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
