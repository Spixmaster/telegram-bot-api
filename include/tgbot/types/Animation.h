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
		std::string file_id;
		std::string file_unique_id;
		int width = -1;
		int height = -1;
		int duration = -1;
		PhotoSize::ptr thumb;
		std::string file_name;
		std::string mime_type;
		int file_size;

		//Constructors
		Animation();

		//@param json: json object of Animation
		Animation(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
