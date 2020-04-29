#ifndef TGBOT_TYPES_FILE_H
#define TGBOT_TYPES_FILE_H

#include <string>
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct File
	 * @brief This object represents a file ready to be downloaded. The file can be downloaded via the link https://api.telegram.org/file/bot<token>/<file_path>.
	 * @details It is guaranteed that the link will be valid for at least 1 hour. When the link expires, a new one can be requested by calling getFile.
	 * @note Maximum file size to download is 20 MB
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
		 * @var file_size
		 * @brief Optional. File size, if known
		 */
		int file_size = -1;
		/**
		 * @var file_path
		 * @brief Optional. File path. Use https://api.telegram.org/file/bot<token>/<file_path> to get the file.
		 */
		std::string file_path;

		//Constructors
		File();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		File(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
