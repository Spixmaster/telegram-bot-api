#ifndef TGBOT_TYPES_INLINEQUERYRESULTCACHEDVOICE_H
#define TGBOT_TYPES_INLINEQUERYRESULTCACHEDVOICE_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct InlineQueryResultCachedVoice : public InlineQueryResult
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQueryResultCachedVoice> ptr;

		//member variables
		std::string type;
		std::string id;
		std::string voice_file_id;
		std::string title;
		std::string caption;
		std::string parse_mode;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;

		//constructors
		InlineQueryResultCachedVoice();

		//@param json: json object of InlineQueryResultCachedVoice
		InlineQueryResultCachedVoice(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
