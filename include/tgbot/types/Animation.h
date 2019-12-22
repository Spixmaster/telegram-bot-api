#ifndef TGBOT_TYPES_ANIMATION_H
#define TGBOT_TYPES_ANIMATION_H

#include <string>
#include "tgbot/types/PhotoSize.h"
#include <rapidjson/document.h>
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct Animation
	{
		//pointer of itself
		typedef std::shared_ptr<Animation> ptr;

		//member variables
		std::string file_id;
		int width = -1;
		int height = -1;
		int duration = -1;
		PhotoSize::ptr thumb;
		std::string file_name;
		std::string mime_type;

		//constructors
		Animation();

		//@param json: json object of Animation
		Animation(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
