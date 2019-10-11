#ifndef TYPES_INLINEQUERYRESULTCONTACT_H
#define TYPES_INLINEQUERYRESULTCONTACT_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	struct InlineQueryResultContact : public InlineQueryResult
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQueryResultContact> ptr;

		//member variables
		std::string type;
		std::string id;
		std::string phone_number;
		std::string first_name;
		std::string last_name;
		std::string vcard;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;
		std::string thumb_url;
		int thumb_width = -1;
		int thumb_height = -1;

		//constructors
		InlineQueryResultContact();

		//@param json: json object of InlineQueryResultContact
		InlineQueryResultContact(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
