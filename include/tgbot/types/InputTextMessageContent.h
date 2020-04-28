#ifndef TGBOT_TYPES_INPUTTEXTMESSAGECONTENT_H
#define TGBOT_TYPES_INPUTTEXTMESSAGECONTENT_H

#include <string>
#include "InputMessageContent.h"
#include "rapidjson/document.h"
#include <memory>

//@brief represents on object in the Telegram bot api

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
		std::string parse_to_json() const noexcept;
	};
}

#endif
