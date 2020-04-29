#ifndef TGBOT_TYPES_PHOTOSIZE_H
#define TGBOT_TYPES_PHOTOSIZE_H

#include <string>
#include "rapidjson/document.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct PhotoSize
	 * @brief This object represents one size of a photo or a file / sticker thumbnail.
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
		/**
		 * @var file_id
		 * @brief Identifier for this file, which can be used to download or reuse the file
		 */
		std::string file_id;
		/**
		 * @var file_unique_id
		 * @brief Unique identifier for this file, which is supposed to be the same over time and for different bots. Can't be used to download or reuse the file.
		 */
		std::string file_unique_id;
		/**
		 * @var width
		 * @brief Photo width
		 */
		int width;
		/**
		 * @var height
		 * @brief Photo height
		 */
		int height;
		/**
		 * @var file_size
		 * @brief Optional. File size
		 */
		int file_size;

		//Constructors
		PhotoSize();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		PhotoSize(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
