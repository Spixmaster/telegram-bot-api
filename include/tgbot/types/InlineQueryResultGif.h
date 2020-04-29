#ifndef TGBOT_TYPES_INLINEQUERYRESULTGIF_H
#define TGBOT_TYPES_INLINEQUERYRESULTGIF_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultGif
	 * @brief Represents a link to an animated GIF file.
	 * @details By default, this animated GIF file will be sent by the user with optional caption.
	 * @details Alternatively, you can use input_message_content to send a message with the specified content instead of the animation.
	 */
	struct InlineQueryResultGif : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultGif> ptr;

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
		 * @var gif_url
		 * @brief A valid URL for the GIF file. File size must not exceed 1MB
		 */
		std::string gif_url;
		/**
		 * @var gif_width
		 * @brief Optional. Width of the GIF
		 */
		int gif_width;
		/**
		 * @var gif_height
		 * @brief Optional. Height of the GIF
		 */
		int gif_height;
		/**
		 * @var gif_duration
		 * @brief Optional. Duration of the GIF
		 */
		int gif_duration;
		/**
		 * @var thumb_url
		 * @brief URL of the static thumbnail for the result (jpeg or gif)
		 */
		std::string thumb_url;
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
		InlineQueryResultGif();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQueryResultGif(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
