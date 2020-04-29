#ifndef TGBOT_TYPES_INLINEQUERYRESULTCACHEDMPEG4GIF_H
#define TGBOT_TYPES_INLINEQUERYRESULTCACHEDMPEG4GIF_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultCachedMpeg4Gif
	 * @brief Represents a link to a video animation (H.264/MPEG-4 AVC video without sound) stored on the Telegram servers.
	 * @details By default, this animated MPEG-4 file will be sent by the user with an optional caption.
	 * @details Alternatively, you can use input_message_content to send a message with the specified content instead of the animation.
	 */
	struct InlineQueryResultCachedMpeg4Gif : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultCachedMpeg4Gif> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the result, must be mpeg4_gif
		 */
		std::string type;
		/**
		 * @var id
		 * @brief Unique identifier for this result, 1-64 bytes
		 */
		std::string id;
		/**
		 * @var mpeg4_file_id
		 * @brief A valid file identifier for the MP4 file
		 */
		std::string mpeg4_file_id;
		/**
		 * @var title
		 * @brief Optional. Title for the result
		 */
		std::string title;
		/**
		 * @var caption
		 * @brief Optional. Caption of the MPEG-4 file to be sent, 0-1024 characters after entities parsing
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
		 * @brief Optional. Content of the message to be sent instead of the video animation
		 */
		InputMessageContent::ptr input_message_content;

		//Constructors
		InlineQueryResultCachedMpeg4Gif();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQueryResultCachedMpeg4Gif(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
