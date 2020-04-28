#ifndef TGBOT_TYPES_FILE_H
#define TGBOT_TYPES_FILE_H

#include <string>
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct File
	 */
	struct File
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<File> ptr;

		//Member variables
		std::string file_id;
		std::string file_unique_id;
		int file_size = -1;
		std::string file_path;

		//Constructors
		File();

		//@param json: json object of File
		File(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
