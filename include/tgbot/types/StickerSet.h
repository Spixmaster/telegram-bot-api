#ifndef TGBOT_TYPES_STICKERSET_H
#define TGBOT_TYPES_STICKERSET_H

#include <string>
#include <vector>
#include "tgbot/types/Sticker.h"
#include "tgbot/SpecialTools.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct StickerSet
	{
		//pointer of itself
		typedef std::shared_ptr<StickerSet> ptr;

		//member variables
		std::string name;
		std::string title;
		bool is_animated;
		bool contains_masks;
		std::vector<Sticker::ptr> sticker;

		//constructors
		StickerSet();

		//@param json: json object of StickerSet
		StickerSet(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
