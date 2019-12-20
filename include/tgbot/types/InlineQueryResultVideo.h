#ifndef TGBOT_TYPES_INLINEQUERYRESULTVIDEO_H
#define TGBOT_TYPES_INLINEQUERYRESULTVIDEO_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct InlineQueryResultVideo : public InlineQueryResult
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQueryResultVideo> ptr;

		//member variables
		std::string type;
		std::string id;
		std::string video_url;
		std::string mime_type;
		std::string thumb_url;
		std::string title;
		std::string caption;
		std::string parse_mode;
		int video_width = -1;
		int video_height = -1;
		int video_duration = -1;
		std::string description;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;

		//constructors
		InlineQueryResultVideo();

		//@param json: json object of InlineQueryResultVideo
		InlineQueryResultVideo(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
