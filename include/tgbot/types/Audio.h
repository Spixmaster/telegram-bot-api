#ifndef TGBOT_TYPES_AUDIO_H
#define TGBOT_TYPES_AUDIO_H

#include <string>
#include "tgbot/types/PhotoSize.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct Audio
	 */
	struct Audio
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Audio> ptr;

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
		int duration = -1;
		/**
		 * @var
		 */
		std::string performer;
		/**
		 * @var
		 */
		std::string title;
		/**
		 * @var
		 */
		std::string mime_type;
		/**
		 * @var
		 */
		int file_size = -1;
		/**
		 * @var
		 */
		PhotoSize::ptr thumb;

		//Constructors
		Audio();

		//@param json: json object of Audio
		Audio(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
