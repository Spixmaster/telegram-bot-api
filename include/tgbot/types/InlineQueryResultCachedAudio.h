#ifndef TGBOT_TYPES_INLINEQUERYRESULTCACHEDAUDIO_H
#define TGBOT_TYPES_INLINEQUERYRESULTCACHEDAUDIO_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultCachedAudio
	 */
	struct InlineQueryResultCachedAudio : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultCachedAudio> ptr;

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
		std::string audio_file_id;
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
		InlineQueryResultCachedAudio();

		//@param json: json object of InlineQueryResultCachedAudio
		InlineQueryResultCachedAudio(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
