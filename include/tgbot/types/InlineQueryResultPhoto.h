#ifndef TGBOT_TYPES_INLINEQUERYRESULTPHOTO_H
#define TGBOT_TYPES_INLINEQUERYRESULTPHOTO_H

#include <string>
#include "tgbot/types/InlineQueryResult.h"
#include <memory>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"

namespace tgbot
{
	/**
	 * @struct InlineQueryResultPhoto
	 */
	struct InlineQueryResultPhoto : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultPhoto> ptr;

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
		std::string photo_url;
		/**
		 * @var
		 */
		std::string thumb_url;
		/**
		 * @var
		 */
		int photo_width = -1;
		/**
		 * @var
		 */
		int photo_height = -1;
		/**
		 * @var
		 */
		std::string title;
		/**
		 * @var
		 */
		std::string description;
		/**
		 * @var
		 */
		std::string caption;
		/**
		 * @var
		 */
		std::string parse_mode;
		/**
		 * @var
		 */
		InlineKeyboardMarkup::ptr reply_markup;
		/**
		 * @var
		 */
		InputMessageContent::ptr input_message_content;

		//Constructors
		InlineQueryResultPhoto();

		//@param json: json object of InlineQueryResultPhoto
		InlineQueryResultPhoto(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
