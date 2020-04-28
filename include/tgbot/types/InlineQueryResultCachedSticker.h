#ifndef TGBOT_TYPES_INLINEQUERYRESULTCACHEDSTICKER_H
#define TGBOT_TYPES_INLINEQUERYRESULTCACHEDSTICKER_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultCachedSticker
	 */
	struct InlineQueryResultCachedSticker : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		std::shared_ptr<InlineQueryResultCachedSticker> ptr;

		//Member variables
		std::string type;
		std::string id;
		std::string sticker_file_id;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;

		//Constructors
		InlineQueryResultCachedSticker();

		//@param json: json object of InlineQueryResultCachedSticker
		InlineQueryResultCachedSticker(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
