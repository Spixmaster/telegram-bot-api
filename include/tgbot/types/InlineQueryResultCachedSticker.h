#ifndef TGBOT_TYPES_INLINEQUERYRESULTCACHEDSTICKER_H
#define TGBOT_TYPES_INLINEQUERYRESULTCACHEDSTICKER_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultCachedSticker
	 * @brief Represents a link to a sticker stored on the Telegram servers.
	 * @details By default, this sticker will be sent by the user.
	 * @details Alternatively, you can use input_message_content to send a message with the specified content instead of the sticker.
	 * @note This will only work in Telegram versions released after 9 April, 2016 for static stickers and after 06 July, 2019 for animated stickers. Older clients will ignore them.
	 */
	struct InlineQueryResultCachedSticker : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		std::shared_ptr<InlineQueryResultCachedSticker> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the result, must be sticker
		 */
		const std::string type = "type";
		/**
		 * @var id
		 * @brief Unique identifier for this result, 1-64 bytes
		 */
		std::string id;
		/**
		 * @var sticker_file_id
		 * @brief A valid file identifier of the sticker
		 */
		std::string sticker_file_id;
		/**
		 * @var reply_markup
		 * @brief Optional. Inline keyboard attached to the message
		 */
		InlineKeyboardMarkup::ptr reply_markup;
		/**
		 * @var input_message_content
		 * @brief Optional. Content of the message to be sent instead of the sticker
		 */
		InputMessageContent::ptr input_message_content;

		//Constructors
		InlineQueryResultCachedSticker();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQueryResultCachedSticker(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
