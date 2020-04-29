#ifndef TGBOT_TYPES_INLINEQUERYRESULTVIDEO_H
#define TGBOT_TYPES_INLINEQUERYRESULTVIDEO_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultVideo
	 * @brief Represents a link to a page containing an embedded video player or a video file.
	 * @details By default, this video file will be sent by the user with an optional caption.
	 * @details Alternatively, you can use input_message_content to send a message with the specified content instead of the video.
	 * @note If an InlineQueryResultVideo message contains an embedded video (e.g., YouTube), you must replace its content using input_message_content.
	 */
	struct InlineQueryResultVideo : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultVideo> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the result, must be video
		 */
		const std::string type = "video";
		/**
		 * @var id
		 * @brief Unique identifier for this result, 1-64 bytes
		 */
		std::string id;
		/**
		 * @var video_url
		 * @brief A valid URL for the embedded video player or video file
		 */
		std::string video_url;
		/**
		 * @var mime_type
		 * @brief Mime type of the content of video url, “text/html” or “video/mp4”
		 */
		std::string mime_type;
		/**
		 * @var thumb_url
		 * @brief URL of the thumbnail (jpeg only) for the video
		 */
		std::string thumb_url;
		/**
		 * @var title
		 * @brief Title for the result
		 */
		std::string title;
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
		 * @var video_width
		 * @brief Optional. Video width
		 */
		int video_width = -1;
		/**
		 * @var video_height
		 * @brief Optional. Video height
		 */
		int video_height = -1;
		/**
		 * @var video_duration
		 * @brief Optional. Video duration in seconds
		 */
		int video_duration = -1;
		/**
		 * @var description
		 * @brief Optional. Short description of the result
		 */
		std::string description;
		/**
		 * @var reply_markup
		 * @brief Optional. Inline keyboard attached to the message
		 */
		InlineKeyboardMarkup::ptr reply_markup;
		/**
		 * @var input_message_content
		 * @brief Optional. Content of the message to be sent instead of the video.
		 * @details This field is required if InlineQueryResultVideo is used to send an HTML-page as a result (e.g., a YouTube video).
		 */
		InputMessageContent::ptr input_message_content;

		//Constructors
		InlineQueryResultVideo();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQueryResultVideo(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
