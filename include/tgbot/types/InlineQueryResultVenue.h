#ifndef TGBOT_TYPES_INLINEQUERYRESULTVENUE_H
#define TGBOT_TYPES_INLINEQUERYRESULTVENUE_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultVenue
	 */
	struct InlineQueryResultVenue : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultVenue> ptr;

		//Member variables
		std::string type;
		std::string id;
		float latitude = -1;
		float longitude = -1;
		std::string title;
		std::string address;
		std::string foursquare_id;
		std::string foursquare_type;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;
		std::string thumb_url;
		int thumb_width = -1;
		int thumb_height = -1;

		//Constructors
		InlineQueryResultVenue();

		//@param json: json object of InlineQueryResultVenue
		InlineQueryResultVenue(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
