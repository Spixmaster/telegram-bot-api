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
		std::string file_id;
		std::string file_unique_id;
		int duration = -1;
		std::string performer;
		std::string title;
		std::string mime_type;
		int file_size = -1;
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
