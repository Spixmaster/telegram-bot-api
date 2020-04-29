#ifndef TGBOT_TYPES_INLINEQUERYRESULTCACHEDPHOTO_H
#define TGBOT_TYPES_INLINEQUERYRESULTCACHEDPHOTO_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultCachedPhoto
	 * @brief Represents a link to a photo stored on the Telegram servers.
	 * @details By default, this photo will be sent by the user with an optional caption.
	 * @details Alternatively, you can use input_message_content to send a message with the specified content instead of the photo.
	 */
	struct InlineQueryResultCachedPhoto : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultCachedPhoto> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the result, must be photo
		 */
		std::string type;
		/**
		 * @var id
		 * @brief Unique identifier for this result, 1-64 bytes
		 */
		std::string id;
		/**
		 * @var photo_file_id
		 * @brief A valid file identifier of the photo
		 */
		std::string photo_file_id;
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
		InlineQueryResultCachedPhoto();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQueryResultCachedPhoto(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
