#ifndef TGBOT_TYPES_INLINEQUERYRESULTMPEG4GIF_H
#define TGBOT_TYPES_INLINEQUERYRESULTMPEG4GIF_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct InlineQueryResultMpeg4Gif : public InlineQueryResult
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQueryResultMpeg4Gif> ptr;

		//member variables
		std::string type;
		std::string id;
		std::string mpeg4_url;
		int mpeg4_width = -1;
		int mpeg4_height = -1;
		int mpeg4_duration = -1;
		std::string thumb_url;
		std::string title;
		std::string caption;
		std::string parse_mode;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;

		//constructors
		InlineQueryResultMpeg4Gif();

		//@param json: json object of InlineQueryResultMpeg4Gif
		InlineQueryResultMpeg4Gif(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
