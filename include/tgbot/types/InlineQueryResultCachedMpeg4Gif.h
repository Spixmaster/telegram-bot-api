#ifndef TGBOT_TYPES_INLINEQUERYRESULTCACHEDMPEG4GIF_H
#define TGBOT_TYPES_INLINEQUERYRESULTCACHEDMPEG4GIF_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct InlineQueryResultCachedMpeg4Gif : public InlineQueryResult
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQueryResultCachedMpeg4Gif> ptr;

		//member variables
		std::string type;
		std::string id;
		std::string mpeg4_file_id;
		std::string title;
		std::string caption;
		std::string parse_mode;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;

		//constructors
		InlineQueryResultCachedMpeg4Gif();

		//@param json: json object of InlineQueryResultCachedMpeg4Gif
		InlineQueryResultCachedMpeg4Gif(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
