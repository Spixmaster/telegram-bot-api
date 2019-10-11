#ifndef TYPES_INLINEQUERYRESULTCACHEDSTICKER_H
#define TYPES_INLINEQUERYRESULTCACHEDSTICKER_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	struct InlineQueryResultCachedSticker : public InlineQueryResult
	{
		//pointer of itself
		std::shared_ptr<InlineQueryResultCachedSticker> ptr;

		//member variables
		std::string type;
		std::string id;
		std::string sticker_file_id;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;

		//constructors
		InlineQueryResultCachedSticker();

		//@param json: json object of InlineQueryResultCachedSticker
		InlineQueryResultCachedSticker(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
