#ifndef TGBOT_TYPES_INLINEQUERYRESULTARTICLE_H
#define TGBOT_TYPES_INLINEQUERYRESULTARTICLE_H

#include <string>
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultArticle
	 */
	struct InlineQueryResultArticle : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultArticle> ptr;

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
		std::string title;
		/**
		 * @var
		 */
		InputMessageContent::ptr input_message_content;
		/**
		 * @var
		 */
		InlineKeyboardMarkup::ptr reply_markup;
		/**
		 * @var
		 */
		std::string url;
		/**
		 * @var
		 */
		bool hide_url;
		/**
		 * @var
		 */
		std::string description;
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
		InlineQueryResultArticle();

		//@param json: json object of InlineQueryResultArticle
		InlineQueryResultArticle(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
