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
		std::string video_url;
		/**
		 * @var
		 */
		std::string mime_type;
		/**
		 * @var
		 */
		std::string thumb_url;
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
		int video_width = -1;
		/**
		 * @var
		 */
		int video_height = -1;
		/**
		 * @var
		 */
		int video_duration = -1;
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
