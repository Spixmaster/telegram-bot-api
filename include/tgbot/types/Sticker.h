#ifndef TGBOT_TYPES_STICKER_H
#define TGBOT_TYPES_STICKER_H

#include <string>
#include "tgbot/types/PhotoSize.h"
#include "tgbot/types/MaskPosition.h"

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct Sticker
	{
		//pointer of itself
		typedef std::shared_ptr<Sticker> ptr;

		//member variables
		std::string file_id;
		int width = -1;
		int height = -1;
		bool is_animated;
		PhotoSize::ptr thumb;
		std::string emoji;
		std::string set_name;
		MaskPosition::ptr mask_position;
		int file_size = -1;

		//constructors
		Sticker();

		//@param json: json object of Sticker
		Sticker(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
