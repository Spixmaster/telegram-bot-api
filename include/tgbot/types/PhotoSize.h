#ifndef TGBOT_TYPES_PHOTOSIZE_H
#define TGBOT_TYPES_PHOTOSIZE_H

#include <string>
#include "rapidjson/document.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct PhotoSize
	{
		//pointer of itself
		typedef std::shared_ptr<PhotoSize> ptr;

		//member variables
		std::string file_id;
		std::string file_unique_id;
		int width = -1;
		int height = -1;
		int file_size = -1;

		//constructors
		PhotoSize();

		//@param json: json object of PhotoSize
		PhotoSize(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
