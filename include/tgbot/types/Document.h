#ifndef TGBOT_TYPES_DOCUMENT_H
#define TGBOT_TYPES_DOCUMENT_H

#include <string>
#include "tgbot/types/PhotoSize.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct Document
	 * @brief This object represents a general file (as opposed to photos, voice messages and audio files).
	 */
	struct Document
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Document> ptr;

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
		 * @var thumb
		 * @brief Optional. Document thumbnail as defined by sender
		 */
		PhotoSize::ptr thumb;
		/**
		 * @var file_name
		 * @brief Optional. Original filename as defined by sender
		 */
		std::string file_name;
		/**
		 * @var mime_type
		 * @brief Optional. MIME type of the file as defined by sender
		 */
		std::string mime_type;
		/**
		 * @var file_size
		 * @brief Optional. File size
		 */
		int file_size;

		//Constructors
		Document();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		Document(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
