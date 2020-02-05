#ifndef TGBOT_TYPES_INLINEQUERYRESULTCACHEDGIF_H
#define TGBOT_TYPES_INLINEQUERYRESULTCACHEDGIF_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct InlineQueryResultCachedGif : public InlineQueryResult
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQueryResultCachedGif> ptr;

		//member variables
		std::string type;
		std::string id;
		std::string gif_file_id;
		std::string title;
		std::string caption;
		std::string parse_mode;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;

		//constructors
		InlineQueryResultCachedGif();

		//@param json: json object of InlineQueryResultCachedGif
		InlineQueryResultCachedGif(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
