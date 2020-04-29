#ifndef TGBOT_TYPES_VIDEO_H
#define TGBOT_TYPES_VIDEO_H

#include <string>
#include "tgbot/types/PhotoSize.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct Video
	 * @brief This object represents a video file.
	 */
	struct Video
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Video> ptr;

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
		 * @brief Video width as defined by sender
		 */
		int width = -1;
		/**
		 * @var height
		 * @brief Video height as defined by sender
		 */
		int height = -1;
		/**
		 * @var duration
		 * @brief Duration of the video in seconds as defined by sender
		 */
		int duration = -1;
		/**
		 * @var thumb
		 * @brief Optional. Video thumbnail
		 */
		PhotoSize::ptr thumb;
		/**
		 * @var mime_type
		 * @brief Optional. Mime type of a file as defined by sender
		 */
		std::string mime_type;
		/**
		 * @var file_size
		 * @brief Optional. File size
		 */
		int file_size = -1;

		//Constructors
		Video();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		Video(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
