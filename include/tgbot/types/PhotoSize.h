#ifndef TGBOT_TYPES_PHOTOSIZE_H
#define TGBOT_TYPES_PHOTOSIZE_H

#include <string>
#include "rapidjson/document.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct PhotoSize
	 */
	struct PhotoSize
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PhotoSize> ptr;

		//Member variables
		std::string file_id;
		std::string file_unique_id;
		int width = -1;
		int height = -1;
		int file_size = -1;

		//Constructors
		PhotoSize();

		//@param json: json object of PhotoSize
		PhotoSize(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
