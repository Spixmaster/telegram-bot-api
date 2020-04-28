#ifndef TGBOT_TYPES_INLINEQUERYRESULTLOCATION_H
#define TGBOT_TYPES_INLINEQUERYRESULTLOCATION_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultLocation
	 */
	struct InlineQueryResultLocation : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultLocation> ptr;

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
		float latitude = -1;
		/**
		 * @var
		 */
		float longitude = -1;
		/**
		 * @var
		 */
		std::string title;
		/**
		 * @var
		 */
		int live_period = -1;
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
		InlineQueryResultLocation();

		//@param json: json object of InlineQueryResultLocation
		InlineQueryResultLocation(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
