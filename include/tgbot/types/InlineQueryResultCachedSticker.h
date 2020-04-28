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
		/**
		 * @var
		 */
		std::string type;
		/**
		 * @var
		 */
		std::string id;
		/**
		 * @var
		 */
		std::string sticker_file_id;
		/**
		 * @var
		 */
		InlineKeyboardMarkup::ptr reply_markup;
		/**
		 * @var
		 */
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
