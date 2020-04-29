#ifndef TGBOT_TYPES_INLINEQUERYRESULTDOCUMENT_H
#define TGBOT_TYPES_INLINEQUERYRESULTDOCUMENT_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultDocument
	 * @brief Represents a link to a file.
	 * @details By default, this file will be sent by the user with an optional caption.
	 * @details Alternatively, you can use input_message_content to send a message with the specified content instead of the file.
	 * @details Currently, only .PDF and .ZIP files can be sent using this method.
	 * @note This will only work in Telegram versions released after 9 April, 2016. Older clients will ignore them.
	 */
	struct InlineQueryResultDocument : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultDocument> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the result, must be document
		 */
		std::string type;
		/**
		 * @var id
		 * @brief Unique identifier for this result, 1-64 bytes
		 */
		std::string id;
		/**
		 * @var title
		 * @brief Title for the result
		 */
		std::string title;
		/**
		 * @var caption
		 * @brief Optional. Caption of the document to be sent, 0-1024 characters after entities parsing
		 */
		std::string caption;
		/**
		 * @var parse_mode
		 * @brief Optional. Mode for parsing entities in the document caption. See formatting options for more details.
		 */
		std::string parse_mode;
		/**
		 * @var document_url
		 * @brief A valid URL for the file
		 */
		std::string document_url;
		/**
		 * @var mime_type
		 * @brief Mime type of the content of the file, either “application/pdf” or “application/zip”
		 */
		std::string mime_type;
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
		 * @brief Optional. Content of the message to be sent instead of the file
		 */
		InputMessageContent::ptr input_message_content;
		/**
		 * @var thumb_url
		 * @brief Optional. URL of the thumbnail (jpeg only) for the file
		 */
		std::string thumb_url;
		/**
		 * @var thumb_width
		 * @brief Optional. Thumbnail width
		 */
		int thumb_width;
		/**
		 * @var thumb_height
		 * @brief Optional. Thumbnail height
		 */
		int thumb_height;

		//Constructors
		InlineQueryResultDocument();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQueryResultDocument(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
