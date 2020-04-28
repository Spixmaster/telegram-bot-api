#ifndef TGBOT_TYPES_INLINEQUERYRESULTVIDEO_H
#define TGBOT_TYPES_INLINEQUERYRESULTVIDEO_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultVideo
	 */
	struct InlineQueryResultVideo : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultVideo> ptr;

		//Member variables
		std::string type;
		std::string id;
		std::string video_url;
		std::string mime_type;
		std::string thumb_url;
		std::string title;
		std::string caption;
		std::string parse_mode;
		int video_width = -1;
		int video_height = -1;
		int video_duration = -1;
		std::string description;
		InlineKeyboardMarkup::ptr reply_markup;
		InputMessageContent::ptr input_message_content;

		//Constructors
		InlineQueryResultVideo();

		//@param json: json object of InlineQueryResultVideo
		InlineQueryResultVideo(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
