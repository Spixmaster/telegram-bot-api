#ifndef TGBOT_TYPES_INLINEQUERYRESULTPHOTO_H
#define TGBOT_TYPES_INLINEQUERYRESULTPHOTO_H

#include <string>
#include "tgbot/types/InlineQueryResult.h"
#include <memory>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"

namespace tgbot
{
	/**
	 * @struct InlineQueryResultPhoto
	 * @brief Represents a link to a photo.
	 * @details By default, this photo will be sent by the user with optional caption.
	 * @details Alternatively, you can use input_message_content to send a message with the specified content instead of the photo.
	 */
	struct InlineQueryResultPhoto : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultPhoto> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the result, must be photo
		 */
		const std::string type = "photo";
		/**
		 * @var id
		 * @brief Unique identifier for this result, 1-64 bytes
		 */
		std::string id;
		/**
		 * @var photo_url
		 * @brief A valid URL of the photo. Photo must be in jpeg format. Photo size must not exceed 5MB
		 */
		std::string photo_url;
		/**
		 * @var thumb_url
		 * @brief URL of the thumbnail for the photo
		 */
		std::string thumb_url;
		/**
		 * @var photo_width
		 * @brief Optional. Width of the photo
		 */
		int photo_width = -1;
		/**
		 * @var photo_height
		 * @brief Optional. Height of the photo
		 */
		int photo_height = -1;
		/**
		 * @var title
		 * @brief Optional. Title for the result
		 */
		std::string title;
		/**
		 * @var description
		 * @brief Optional. Short description of the result
		 */
		std::string description;
		/**
		 * @var caption
		 * @brief Optional. Caption of the photo to be sent, 0-1024 characters after entities parsing
		 */
		std::string caption;
		/**
		 * @var parse_mode
		 * @brief Optional. Mode for parsing entities in the photo caption. See formatting options for more details.
		 */
		std::string parse_mode;
		/**
		 * @var reply_markup
		 * @brief Optional. Inline keyboard attached to the message
		 */
		InlineKeyboardMarkup::ptr reply_markup;
		/**
		 * @var input_message_content
		 * @brief Optional. Content of the message to be sent instead of the photo
		 */
		InputMessageContent::ptr input_message_content;

		//Constructors
		InlineQueryResultPhoto();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQueryResultPhoto(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
