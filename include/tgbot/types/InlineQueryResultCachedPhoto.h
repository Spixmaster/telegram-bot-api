#ifndef TGBOT_TYPES_INLINEQUERYRESULTCACHEDPHOTO_H
#define TGBOT_TYPES_INLINEQUERYRESULTCACHEDPHOTO_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct InlineQueryResultCachedPhoto : public InlineQueryResult
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQueryResultCachedPhoto> ptr;

		//member variables
		std::string type;
		std::string id;
		std::string photo_file_id;
		std::string title;
		std::string description;
		std::string caption;
		std::string parse_mode;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;

		//constructors
		InlineQueryResultCachedPhoto();

		//@param json: json object of InlineQueryResultCachedPhoto
		InlineQueryResultCachedPhoto(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
