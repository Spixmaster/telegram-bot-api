#ifndef TGBOT_TYPES_STICKER_H
#define TGBOT_TYPES_STICKER_H

#include <string>
#include "tgbot/types/PhotoSize.h"
#include "tgbot/types/MaskPosition.h"

namespace tgbot
{
	/**
	 * @struct Sticker
	 * @brief This object represents a sticker.
	 */
	struct Sticker
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Sticker> ptr;

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
		 * @brief Sticker width
		 */
		int width = -1;
		/**
		 * @var height
		 * @brief Sticker height
		 */
		int height = -1;
		/**
		 * @var is_animated
		 * @brief True, if the sticker is animated
		 */
		bool is_animated;
		/**
		 * @var thumb
		 * @brief Optional. Sticker thumbnail in the .WEBP or .JPG format
		 */
		PhotoSize::ptr thumb;
		/**
		 * @var emoji
		 * @brief Optional. Emoji associated with the sticker
		 */
		std::string emoji;
		/**
		 * @var set_name
		 * @brief Optional. Name of the sticker set to which the sticker belongs
		 */
		std::string set_name;
		/**
		 * @var mask_position
		 * @brief Optional. For mask stickers, the position where the mask should be placed
		 */
		MaskPosition::ptr mask_position;
		/**
		 * @var file_size
		 * @brief Optional. File size
		 */
		int file_size = -1;

		//Constructors
		Sticker();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		Sticker(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
