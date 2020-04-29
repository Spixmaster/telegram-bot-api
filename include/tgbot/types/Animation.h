#ifndef TGBOT_TYPES_ANIMATION_H
#define TGBOT_TYPES_ANIMATION_H

#include <string>
#include "tgbot/types/PhotoSize.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct Animation
	 * @brief This object represents an animation file (GIF or H.264/MPEG-4 AVC video without sound).
	 */
	struct Animation
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Animation> ptr;

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
		 * @brief Optional. Animation thumbnail as defined by sender
		 */
		PhotoSize::ptr thumb;
		/**
		 * @var file_name
		 * @brief Optional. Original animation filename as defined by sender
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
		Animation();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		Animation(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
