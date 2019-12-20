#ifndef TGBOT_TYPES_INLINEQUERYRESULTDOCUMENT_H
#define TGBOT_TYPES_INLINEQUERYRESULTDOCUMENT_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct InlineQueryResultDocument : public InlineQueryResult
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQueryResultDocument> ptr;

		//member variables
		std::string type;
		std::string id;
		std::string title;
		std::string caption;
		std::string parse_mode;
		std::string document_url;
		std::string mime_type;
		std::string description;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;
		std::string thumb_url;
		int thumb_width = -1;
		int thumb_height = -1;

		//constructors
		InlineQueryResultDocument();

		//@param json: json object of InlineQueryResultDocument
		InlineQueryResultDocument(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
