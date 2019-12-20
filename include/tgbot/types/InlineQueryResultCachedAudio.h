#ifndef TGBOT_TYPES_INLINEQUERYRESULTCACHEDAUDIO_H
#define TGBOT_TYPES_INLINEQUERYRESULTCACHEDAUDIO_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct InlineQueryResultCachedAudio : public InlineQueryResult
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQueryResultCachedAudio> ptr;

		//member variables
		std::string type;
		std::string id;
		std::string audio_file_id;
		std::string caption;
		std::string parse_mode;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;

		//constructors
		InlineQueryResultCachedAudio();

		//@param json: json object of InlineQueryResultCachedAudio
		InlineQueryResultCachedAudio(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
