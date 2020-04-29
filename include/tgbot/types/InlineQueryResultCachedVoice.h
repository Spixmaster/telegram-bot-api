#ifndef TGBOT_TYPES_INLINEQUERYRESULTCACHEDVOICE_H
#define TGBOT_TYPES_INLINEQUERYRESULTCACHEDVOICE_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultCachedVoice
	 * @brief Represents a link to a voice message stored on the Telegram servers.
	 * @details By default, this voice message will be sent by the user.
	 * @details Alternatively, you can use input_message_content to send a message with the specified content instead of the voice message.
	 * @note This will only work in Telegram versions released after 9 April, 2016. Older clients will ignore them.
	 */
	struct InlineQueryResultCachedVoice : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultCachedVoice> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the result, must be voice
		 */
		std::string type;
		/**
		 * @var id
		 * @brief Unique identifier for this result, 1-64 bytes
		 */
		std::string id;
		/**
		 * @var voice_file_id
		 * @brief A valid file identifier for the voice message
		 */
		std::string voice_file_id;
		/**
		 * @var title
		 * @brief Voice message title
		 */
		std::string title;
		/**
		 * @var caption
		 * @brief Optional. Caption, 0-1024 characters after entities parsing
		 */
		std::string caption;
		/**
		 * @var parse_mode
		 * @brief Optional. Mode for parsing entities in the voice message caption. See formatting options for more details.
		 */
		std::string parse_mode;
		/**
		 * @var reply_markup
		 * @brief Optional. Inline keyboard attached to the message
		 */
		InlineKeyboardMarkup::ptr reply_markup;
		/**
		 * @var input_message_content
		 * @brief Optional. Content of the message to be sent instead of the voice message
		 */
		InputMessageContent::ptr input_message_content;

		//Constructors
		InlineQueryResultCachedVoice();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQueryResultCachedVoice(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
