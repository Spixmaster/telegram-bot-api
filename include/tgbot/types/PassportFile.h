#ifndef TGBOT_TYPES_PASSPORTFILE_H
#define TGBOT_TYPES_PASSPORTFILE_H

#include <string>
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportFile
	 */
	struct PassportFile
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PassportFile> ptr;

		//Member variables
		/**
		 * @var
		 */
		std::string file_id;
		/**
		 * @var
		 */
		std::string file_unique_id;
		/**
		 * @var
		 */
		int file_size = -1;
		/**
		 * @var
		 */
		int file_date = -1;

		//Constructors
		PassportFile();

		//@param json: json object of PassportFile
		PassportFile(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
