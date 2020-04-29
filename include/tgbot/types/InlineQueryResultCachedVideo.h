#ifndef TGBOT_TYPES_INLINEQUERYRESULTCACHEDVIDEO_H
#define TGBOT_TYPES_INLINEQUERYRESULTCACHEDVIDEO_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultCachedVideo
	 * @brief Represents a link to a video file stored on the Telegram servers.
	 * @details By default, this video file will be sent by the user with an optional caption.
	 * @details Alternatively, you can use input_message_content to send a message with the specified content instead of the video.
	 */
	struct InlineQueryResultCachedVideo : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultCachedVideo> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the result, must be video
		 */
		std::string type;
		/**
		 * @var id
		 * @brief Unique identifier for this result, 1-64 bytes
		 */
		std::string id;
		/**
		 * @var video_file_id
		 * @brief A valid file identifier for the video file
		 */
		std::string video_file_id;
		/**
		 * @var title
		 * @brief Title for the result
		 */
		std::string title;
		/**
		 * @var description
		 * @brief Optional. Short description of the result
		 */
		std::string description;
		/**
		 * @var caption
		 * @brief Optional. Caption of the video to be sent, 0-1024 characters after entities parsing
		 */
		std::string caption;
		/**
		 * @var parse_mode
		 * @brief Optional. Mode for parsing entities in the video caption. See formatting options for more details.
		 */
		std::string parse_mode;
		/**
		 * @var reply_markup
		 * @brief Optional. Inline keyboard attached to the message
		 */
		InlineKeyboardMarkup::ptr reply_markup;
		/**
		 * @var input_message_content
		 * @brief Optional. Content of the message to be sent instead of the video
		 */
		InputMessageContent::ptr input_message_content;

		//Constructors
		InlineQueryResultCachedVideo();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQueryResultCachedVideo(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
