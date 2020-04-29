#ifndef TGBOT_TYPES_INLINEQUERYRESULTARTICLE_H
#define TGBOT_TYPES_INLINEQUERYRESULTARTICLE_H

#include <string>
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultArticle
	 * @brief Represents a link to an article or web page.
	 */
	struct InlineQueryResultArticle : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultArticle> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the result, must be article
		 */
		std::string type;
		/**
		 * @var id
		 * @brief Unique identifier for this result, 1-64 Bytes
		 */
		std::string id;
		/**
		 * @var title
		 * @brief Title of the result
		 */
		std::string title;
		/**
		 * @var input_message_content
		 * @brief Content of the message to be sent
		 */
		InputMessageContent::ptr input_message_content;
		/**
		 * @var reply_markup
		 * @brief Optional. Inline keyboard attached to the message
		 */
		InlineKeyboardMarkup::ptr reply_markup;
		/**
		 * @var url
		 * @brief Optional. URL of the result
		 */
		std::string url;
		/**
		 * @var hide_url
		 * @brief Optional. Pass True, if you don't want the URL to be shown in the message
		 */
		bool hide_url;
		/**
		 * @var description
		 * @brief Optional. Short description of the result
		 */
		std::string description;
		/**
		 * @var thumb_url
		 * @brief Optional. Url of the thumbnail for the result
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
		InlineQueryResultArticle();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQueryResultArticle(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
