#ifndef TGBOT_TYPES_INLINEQUERYRESULTPHOTO_H
#define TGBOT_TYPES_INLINEQUERYRESULTPHOTO_H

#include <string>
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct InlineQueryResultPhoto : public InlineQueryResult
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQueryResultPhoto> ptr;

		//member variables
		std::string type;
		std::string id;
		std::string photo_url;
		std::string thumb_url;
		int photo_width = -1;
		int photo_height = -1;
		std::string title;
		std::string description;
		std::string caption;
		std::string parse_mode;

		//constructors
		InlineQueryResultPhoto();

		//@param json: json object of InlineQueryResultPhoto
		InlineQueryResultPhoto(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
