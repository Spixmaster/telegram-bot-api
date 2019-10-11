#ifndef TYPES_AUDIO_H
#define TYPES_AUDIO_H

#include <string>
#include "tgbot/types/PhotoSize.h"
#include <rapidjson/document.h>
#include "tgbot/special_tools.h"
#include <memory>

namespace tgbot
{
	struct Audio
	{
		//pointer of itself
		typedef std::shared_ptr<Audio> ptr;

		//member variables
		std::string file_id;
		int duration = -1;
		std::string performer;
		std::string title;
		std::string mime_type;
		int file_size = -1;
		PhotoSize::ptr thumb;

		//constructors
		Audio();

		//@param json: json object of Audio
		Audio(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
