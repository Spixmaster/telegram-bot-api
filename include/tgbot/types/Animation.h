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
		int duration = -1;
		/**
		 * @var
		 */
		PhotoSize::ptr thumb;
		/**
		 * @var
		 */
		std::string file_name;
		/**
		 * @var
		 */
		std::string mime_type;
		/**
		 * @var
		 */
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
