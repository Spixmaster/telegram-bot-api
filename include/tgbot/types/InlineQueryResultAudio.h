#ifndef TGBOT_TYPES_INLINEQUERYRESULTAUDIO_H
#define TGBOT_TYPES_INLINEQUERYRESULTAUDIO_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultAudio
	 */
	struct InlineQueryResultAudio : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultAudio> ptr;

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
		std::string audio_url;
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
		std::string performer;
		/**
		 * @var
		 */
		int audio_duration = -1;

		InlineKeyboardMarkup::ptr reply_markup;

		InputMessageContent::ptr input_message_content;

		//Constructors
		InlineQueryResultAudio();

		//@param json: json object of InlineQueryResultAudio
		InlineQueryResultAudio(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
