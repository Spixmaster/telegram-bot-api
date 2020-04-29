#ifndef TGBOT_TYPES_CHATPHOTO_H
#define TGBOT_TYPES_CHATPHOTO_H

#include <string>
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct ChatPhoto
	 * @brief This object represents a chat photo.
	 */
	struct ChatPhoto
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<ChatPhoto> ptr;

		//Member variables
		/**
		 * @var small_file_id
		 * @brief File identifier of small (160x160) chat photo. This file_id can be used only for photo download and only for as long as the photo is not changed.
		 */
		std::string small_file_id;
		/**
		 * @var small_file_unique_id
		 * @brief Unique file identifier of small (160x160) chat photo, which is supposed to be the same over time and for different bots. Can't be used to download or reuse the file.
		 */
		std::string small_file_unique_id;
		/**
		 * @var big_file_id
		 * @brief File identifier of big (640x640) chat photo. This file_id can be used only for photo download and only for as long as the photo is not changed.
		 */
		std::string big_file_id;
		/**
		 * @var big_file_unique_id
		 * @brief Unique file identifier of big (640x640) chat photo, which is supposed to be the same over time and for different bots. Can't be used to download or reuse the file.
		 */
		std::string big_file_unique_id;

		//Constructors
		ChatPhoto();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		ChatPhoto(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
