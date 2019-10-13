#ifndef TGBOT_TYPES_INLINEQUERYRESULTARTICLE_H
#define TGBOT_TYPES_INLINEQUERYRESULTARTICLE_H

#include <string>
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InlineQueryResult.h"
#include "tgbot/SpecialTools.h"
#include <memory>

namespace tgbot
{
	struct InlineQueryResultArticle : public InlineQueryResult
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQueryResultArticle> ptr;

		//member variables
		std::string type;
		std::string id;
		std::string title;
		InputMessageContent::ptr input_message_content;
		InlineKeyboardMarkup::ptr reply_markup;
		std::string url;
		bool hide_url;
		std::string description;
		std::string thumb_url;
		int thumb_width = -1;
		int thumb_height = -1;

		//constructors
		InlineQueryResultArticle();

		//@param json: json object of InlineQueryResultArticle
		InlineQueryResultArticle(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
