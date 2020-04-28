#ifndef TGBOT_TYPES_STICKER_H
#define TGBOT_TYPES_STICKER_H

#include <string>
#include "tgbot/types/PhotoSize.h"
#include "tgbot/types/MaskPosition.h"

namespace tgbot
{
	/**
	 * @struct Sticker
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
		std::string file_id;
		std::string file_unique_id;
		int width = -1;
		int height = -1;
		bool is_animated;
		PhotoSize::ptr thumb;
		std::string emoji;
		std::string set_name;
		MaskPosition::ptr mask_position;
		int file_size = -1;

		//Constructors
		Sticker();

		//@param json: json object of Sticker
		Sticker(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
