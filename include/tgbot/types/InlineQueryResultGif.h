#ifndef TYPES_INLINEQUERYRESULTGIF_H
#define TYPES_INLINEQUERYRESULTGIF_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	struct InlineQueryResultGif : public InlineQueryResult
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQueryResultGif> ptr;

		//member variables
		std::string type;
		std::string id;
		std::string gif_url;
		int gif_width = -1;
		int gif_height = -1;
		int gif_duration = -1;
		std::string thumb_url;
		std::string title;
		std::string caption;
		std::string parse_mode;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;

		//constructors
		InlineQueryResultGif();

		//@param json: json object of InlineQueryResultGif
		InlineQueryResultGif(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
