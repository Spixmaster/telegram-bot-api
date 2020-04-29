#ifndef TGBOT_TYPES_INLINEQUERYRESULTCACHEDGIF_H
#define TGBOT_TYPES_INLINEQUERYRESULTCACHEDGIF_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultCachedGif
	 * @brief Represents a link to an animated GIF file stored on the Telegram servers.
	 * @details By default, this animated GIF file will be sent by the user with an optional caption.
	 * @details Alternatively, you can use input_message_content to send a message with specified content instead of the animation.
	 */
	struct InlineQueryResultCachedGif : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultCachedGif> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the result, must be gif
		 */
		std::string type;
		/**
		 * @var id
		 * @brief Unique identifier for this result, 1-64 bytes
		 */
		std::string id;
		/**
		 * @var gif_file_id
		 * @brief A valid file identifier for the GIF file
		 */
		std::string gif_file_id;
		/**
		 * @var title
		 * @brief Optional. Title for the result
		 */
		std::string title;
		/**
		 * @var caption
		 * @brief Optional. Caption of the GIF file to be sent, 0-1024 characters after entities parsing
		 */
		std::string caption;
		/**
		 * @var parse_mode
		 * @brief Optional. Mode for parsing entities in the caption. See formatting options for more details.
		 */
		std::string parse_mode;
		/**
		 * @var reply_markup
		 * @brief Optional. Inline keyboard attached to the message
		 */
		InlineKeyboardMarkup::ptr reply_markup;
		/**
		 * @var input_message_content
		 * @brief Optional. Content of the message to be sent instead of the GIF animation
		 */
		InputMessageContent::ptr input_message_content;

		//Constructors
		InlineQueryResultCachedGif();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQueryResultCachedGif(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
