#ifndef TGBOT_TYPES_VIDEONOTE_H
#define TGBOT_TYPES_VIDEONOTE_H

#include <string>
#include "tgbot/types/PhotoSize.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct VideoNote
	 * @brief This object represents a video message (available in Telegram apps as of v.4.0).
	 */
	struct VideoNote
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<VideoNote> ptr;

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
		 * @var length
		 * @brief Video width and height (diameter of the video message) as defined by sender
		 */
		int length;
		/**
		 * @var duration
		 * @brief Duration of the video in seconds as defined by sender
		 */
		int duration;
		/**
		 * @var thumb
		 * @brief Optional. Video thumbnail
		 */
		PhotoSize::ptr thumb;
		/**
		 * @var file_size
		 * @brief Optional. File size
		 */
		int file_size;

		//Constructors
		VideoNote();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		VideoNote(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
