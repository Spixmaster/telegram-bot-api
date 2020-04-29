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
	 * @brief Represents the content of a text message to be sent as the result of an inline query.
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
		/**
		 * @var message_text
		 * @brief Text of the message to be sent, 1-4096 characters
		 */
		std::string message_text;
		/**
		 * @var parse_mode
		 * @brief Optional. Mode for parsing entities in the message text. See formatting options for more details.
		 */
		std::string parse_mode;
		/**
		 * @var disable_web_page_preview
		 * @brief Optional. Disables link previews for links in the sent message
		 */
		bool disable_web_page_preview;

		//Constructors
		InputTextMessageContent();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InputTextMessageContent(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
