#ifndef TGBOT_TYPES_VIDEONOTE_H
#define TGBOT_TYPES_VIDEONOTE_H

#include <string>
#include "tgbot/types/PhotoSize.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct VideoNote
	{
		//pointer of itself
		typedef std::shared_ptr<VideoNote> ptr;

		//member variables
		std::string file_id;
		std::string file_unique_id;
		int length = -1;
		int duration = -1;
		PhotoSize::ptr thumb;
		int file_size = -1;

		//constructors
		VideoNote();

		//@param json: json object of VideoNote
		VideoNote(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
