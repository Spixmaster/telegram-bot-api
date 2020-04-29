#ifndef TGBOT_TYPES_AUDIO_H
#define TGBOT_TYPES_AUDIO_H

#include <string>
#include "tgbot/types/PhotoSize.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct Audio
	 * @brief This object represents an audio file to be treated as music by the Telegram clients.
	 */
	struct Audio
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Audio> ptr;

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
		int duration;
		/**
		 * @var performer
		 * @brief Optional. Performer of the audio as defined by sender or by audio tags
		 */
		std::string performer;
		/**
		 * @var title
		 * @brief Optional. Title of the audio as defined by sender or by audio tags
		 */
		std::string title;
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
		/**
		 * @var thumb
		 * @brief Optional. Thumbnail of the album cover to which the music file belongs
		 */
		PhotoSize::ptr thumb;

		//Constructors
		Audio();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		Audio(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
