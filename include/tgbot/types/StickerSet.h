#ifndef TGBOT_TYPES_STICKERSET_H
#define TGBOT_TYPES_STICKERSET_H

#include <string>
#include <vector>
#include "tgbot/types/Sticker.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct StickerSet
	 * @brief This object represents a sticker set.
	 */
	struct StickerSet
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<StickerSet> ptr;

		//Member variables
		/**
		 * @var name
		 * @brief Sticker set name
		 */
		std::string name;
		/**
		 * @var title
		 * @brief Sticker set title
		 */
		std::string title;
		/**
		 * @var is_animated
		 * @brief True, if the sticker set contains animated stickers
		 */
		bool is_animated;
		/**
		 * @var contains_masks
		 * @brief True, if the sticker set contains masks
		 */
		bool contains_masks;
		/**
		 * @var sticker
		 * @brief List of all set stickers
		 */
		std::vector<Sticker::ptr> sticker;
		/**
		 * @var thumb
		 * @brief Optional. Sticker set thumbnail in the .WEBP or .TGS format
		 */
		PhotoSize::ptr thumb;

		//Constructors
		StickerSet();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		StickerSet(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
