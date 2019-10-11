#ifndef TYPES_INLINEQUERYRESULTCACHEDDOCUMENT_H
#define TYPES_INLINEQUERYRESULTCACHEDDOCUMENT_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	struct InlineQueryResultCachedDocument : public InlineQueryResult
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQueryResultCachedDocument> ptr;

		//member variables
		std::string type;
		std::string id;
		std::string title;
		std::string document_file_id;
		std::string description;
		std::string caption;
		std::string parse_mode;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;

		//constructors
		InlineQueryResultCachedDocument();

		//@param json: json object of InlineQueryResultCachedDocument
		InlineQueryResultCachedDocument(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
