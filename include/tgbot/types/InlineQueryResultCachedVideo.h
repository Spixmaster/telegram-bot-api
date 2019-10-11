#ifndef TGBOT_TYPES_INLINEQUERYRESULTCACHEDVIDEO_H
#define TGBOT_TYPES_INLINEQUERYRESULTCACHEDVIDEO_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	struct InlineQueryResultCachedVideo : public InlineQueryResult
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQueryResultCachedVideo> ptr;

		//member variables
		std::string type;
		std::string id;
		std::string video_file_id;
		std::string title;
		std::string description;
		std::string caption;
		std::string parse_mode;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;

		//constructors
		InlineQueryResultCachedVideo();

		//@param json: json object of InlineQueryResultCachedVideo
		InlineQueryResultCachedVideo(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
