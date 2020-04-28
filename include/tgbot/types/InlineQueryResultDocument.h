#ifndef TGBOT_TYPES_INLINEQUERYRESULTDOCUMENT_H
#define TGBOT_TYPES_INLINEQUERYRESULTDOCUMENT_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultDocument
	 */
	struct InlineQueryResultDocument : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultDocument> ptr;

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
		std::string caption;
		/**
		 * @var
		 */
		std::string parse_mode;
		/**
		 * @var
		 */
		std::string document_url;
		/**
		 * @var
		 */
		std::string mime_type;
		/**
		 * @var
		 */
		std::string description;
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
		InlineQueryResultDocument();

		//@param json: json object of InlineQueryResultDocument
		InlineQueryResultDocument(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
