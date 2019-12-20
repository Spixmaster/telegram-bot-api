#ifndef TGBOT_TYPES_INLINEQUERYRESULTAUDIO_H
#define TGBOT_TYPES_INLINEQUERYRESULTAUDIO_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include "tgbot/SpecialTools.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct InlineQueryResultAudio : public InlineQueryResult
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQueryResultAudio> ptr;

		//member variables
		std::string type;
		std::string id;
		std::string audio_url;
		std::string title;
		std::string caption;
		std::string parse_mode;
		std::string performer;
		int audio_duration = -1;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;

		//constructors
		InlineQueryResultAudio();

		//@param json: json object of InlineQueryResultAudio
		InlineQueryResultAudio(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
