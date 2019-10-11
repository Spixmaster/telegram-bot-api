#ifndef TYPES_FILE_H
#define TYPES_FILE_H

#include <string>
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	struct File
	{
		//pointer of itself
		typedef std::shared_ptr<File> ptr;

		//member variables
		std::string file_id;
		int file_size = -1;
		std::string file_path;

		//constructors
		File();

		//@param json: json object of File
		File(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
