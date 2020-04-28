#ifndef TGBOT_TYPES_INLINEQUERYRESULTCACHEDMPEG4GIF_H
#define TGBOT_TYPES_INLINEQUERYRESULTCACHEDMPEG4GIF_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultCachedMpeg4Gif
	 */
	struct InlineQueryResultCachedMpeg4Gif : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultCachedMpeg4Gif> ptr;

		//Member variables
		std::string type;
		std::string id;
		std::string mpeg4_file_id;
		std::string title;
		std::string caption;
		std::string parse_mode;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;

		//Constructors
		InlineQueryResultCachedMpeg4Gif();

		//@param json: json object of InlineQueryResultCachedMpeg4Gif
		InlineQueryResultCachedMpeg4Gif(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
