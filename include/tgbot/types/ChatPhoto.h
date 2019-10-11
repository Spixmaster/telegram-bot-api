#ifndef TGBOT_TYPES_CHATPHOTO_H
#define TGBOT_TYPES_CHATPHOTO_H

#include <string>
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	struct ChatPhoto
	{
		//pointer of itself
		typedef std::shared_ptr<ChatPhoto> ptr;

		//member variables
		std::string small_file_id;
		std::string big_file_id;

		//constructors
		ChatPhoto();

		//@param json: json object of ChatPhoto
		ChatPhoto(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
