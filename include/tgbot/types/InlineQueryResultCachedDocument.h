#ifndef TGBOT_TYPES_INLINEQUERYRESULTCACHEDDOCUMENT_H
#define TGBOT_TYPES_INLINEQUERYRESULTCACHEDDOCUMENT_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultCachedDocument
	 * @brief Represents a link to a file stored on the Telegram servers.
	 * @details By default, this file will be sent by the user with an optional caption.
	 * @details Alternatively, you can use input_message_content to send a message with the specified content instead of the file.
	 * @note This will only work in Telegram versions released after 9 April, 2016. Older clients will ignore them.
	 */
	struct InlineQueryResultCachedDocument : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultCachedDocument> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the result, must be document
		 */
		const std::string type = "document";
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
		 * @var document_file_id
		 * @brief A valid file identifier for the file
		 */
		std::string document_file_id;
		/**
		 * @var description
		 * @brief Optional. Short description of the result
		 */
		std::string description;
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
		 * @var reply_markup
		 * @brief Optional. Inline keyboard attached to the message
		 */
		InlineKeyboardMarkup::ptr reply_markup;
		/**
		 * @var input_message_content
		 * @brief Optional. Content of the message to be sent instead of the file
		 */
		InputMessageContent::ptr input_message_content;

		//Constructors
		InlineQueryResultCachedDocument();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQueryResultCachedDocument(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
