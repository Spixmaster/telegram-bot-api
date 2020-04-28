#ifndef TGBOT_TYPES_INLINEQUERYRESULTMPEG4GIF_H
#define TGBOT_TYPES_INLINEQUERYRESULTMPEG4GIF_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultMpeg4Gif
	 */
	struct InlineQueryResultMpeg4Gif : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultMpeg4Gif> ptr;

		//Member variables
		std::string type;
		std::string id;
		std::string mpeg4_url;
		int mpeg4_width = -1;
		int mpeg4_height = -1;
		int mpeg4_duration = -1;
		std::string thumb_url;
		std::string title;
		std::string caption;
		std::string parse_mode;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;

		//Constructors
		InlineQueryResultMpeg4Gif();

		//@param json: json object of InlineQueryResultMpeg4Gif
		InlineQueryResultMpeg4Gif(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
