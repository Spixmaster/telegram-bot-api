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
		 * @var
		 */
		std::string name;
		/**
		 * @var
		 */
		std::string title;
		/**
		 * @var
		 */
		bool is_animated;
		/**
		 * @var
		 */
		bool contains_masks;
		/**
		 * @var
		 */
		std::vector<Sticker::ptr> sticker;

		//Constructors
		StickerSet();

		//@param json: json object of StickerSet
		StickerSet(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
