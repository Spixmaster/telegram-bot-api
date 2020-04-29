#ifndef TGBOT_TYPES_PASSPORTFILE_H
#define TGBOT_TYPES_PASSPORTFILE_H

#include <string>
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportFile
	 * @brief  This object represents a file uploaded to Telegram Passport.
	 * @details Currently all Telegram Passport files are in JPEG format when decrypted and don't exceed 10MB.
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
		 * @brief File size
		 */
		int file_size;
		/**
		 * @var file_date
		 * @brief Unix time when the file was uploaded
		 */
		int file_date;

		//Constructors
		PassportFile();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		PassportFile(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
