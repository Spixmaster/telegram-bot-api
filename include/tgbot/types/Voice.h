#ifndef TGBOT_TYPES_VOICE_H
#define TGBOT_TYPES_VOICE_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct Voice
	 * @brief This object represents a voice note.
	 */
	struct Voice
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Voice> ptr;

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
		 * @var duration
		 * @brief Duration of the audio in seconds as defined by sender
		 */
		int duration = -1;
		/**
		 * @var mime_type
		 * @brief Optional. MIME type of the file as defined by sender
		 */
		std::string mime_type;
		/**
		 * @var file_size
		 * @brief Optional. File size
		 */
		int file_size = -1;

		//Constructors
		Voice();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		Voice(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
