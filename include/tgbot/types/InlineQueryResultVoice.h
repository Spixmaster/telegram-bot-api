#ifndef TGBOT_TYPES_INLINEQUERYRESULTVOICE_H
#define TGBOT_TYPES_INLINEQUERYRESULTVOICE_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultVoice
	 */
	struct InlineQueryResultVoice : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultVoice> ptr;

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
		std::string voice_url;
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
		int voice_duration;
		/**
		 * @var
		 */
		InlineKeyboardMarkup::ptr reply_markup;
		/**
		 * @var
		 */
		InputMessageContent::ptr input_message_content;

		//Constructors
		InlineQueryResultVoice();

		//@param json: json object of InlineQueryResultVoice
		InlineQueryResultVoice(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
