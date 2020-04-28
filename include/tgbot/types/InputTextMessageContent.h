#ifndef TGBOT_TYPES_INPUTTEXTMESSAGECONTENT_H
#define TGBOT_TYPES_INPUTTEXTMESSAGECONTENT_H

#include <string>
#include "InputMessageContent.h"
#include "rapidjson/document.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InputTextMessageContent
	 */
	struct InputTextMessageContent : public InputMessageContent
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InputTextMessageContent> ptr;

		//Member variables
		std::string message_text;
		std::string parse_mode;
		bool disable_web_page_preview;

		//Constructors
		InputTextMessageContent();

		//@param json: json object of InputTextMessageContent
		InputTextMessageContent(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
