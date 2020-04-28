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
		/**
		 * @var
		 */
		std::string file_id;
		/**
		 * @var
		 */
		std::string file_unique_id;
		/**
		 * @var
		 */
		int width = -1;
		/**
		 * @var
		 */
		int height = -1;
		/**
		 * @var
		 */
		bool is_animated;
		/**
		 * @var
		 */
		PhotoSize::ptr thumb;
		/**
		 * @var
		 */
		std::string emoji;
		/**
		 * @var
		 */
		std::string set_name;
		/**
		 * @var
		 */
		MaskPosition::ptr mask_position;
		/**
		 * @var
		 */
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
