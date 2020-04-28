#ifndef TGBOT_TYPES_INLINEQUERYRESULTCONTACT_H
#define TGBOT_TYPES_INLINEQUERYRESULTCONTACT_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultContact
	 */
	struct InlineQueryResultContact : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultContact> ptr;

		//Member variables
		/**
		 * @var
		 */
		std::string type;
		/**
		 * @var
		 */
		std::string id;
		/**
		 * @var
		 */
		std::string phone_number;
		/**
		 * @var
		 */
		std::string first_name;
		/**
		 * @var
		 */
		std::string last_name;
		/**
		 * @var
		 */
		std::string vcard;
		/**
		 * @var
		 */
		InlineKeyboardMarkup::ptr reply_markup;
		/**
		 * @var
		 */
		InputMessageContent::ptr input_message_content;
		/**
		 * @var
		 */
		std::string thumb_url;
		/**
		 * @var
		 */
		int thumb_width = -1;
		/**
		 * @var
		 */
		int thumb_height = -1;

		//Constructors
		InlineQueryResultContact();

		//@param json: json object of InlineQueryResultContact
		InlineQueryResultContact(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
