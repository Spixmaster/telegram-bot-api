#ifndef TGBOT_TYPES_PASSPORTFILE_H
#define TGBOT_TYPES_PASSPORTFILE_H

#include <string>
#include <rapidjson/document.h>
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct PassportFile
	{
		//pointer of itself
		typedef std::shared_ptr<PassportFile> ptr;

		//member variables
		std::string file_id;
		std::string file_unique_id;
		int file_size = -1;
		int file_date = -1;

		//constructors
		PassportFile();

		//@param json: json object of PassportFile
		PassportFile(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
