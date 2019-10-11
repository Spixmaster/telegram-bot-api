#ifndef TYPES_INLINEQUERYRESULTVOICE_H
#define TYPES_INLINEQUERYRESULTVOICE_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	struct InlineQueryResultVoice : public InlineQueryResult
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQueryResultVoice> ptr;

		//member variables
		std::string type;
		std::string id;
		std::string voice_url;
		std::string title;
		std::string caption;
		std::string parse_mode;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;

		//constructors
		InlineQueryResultVoice();

		//@param json: json object of InlineQueryResultVoice
		InlineQueryResultVoice(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
