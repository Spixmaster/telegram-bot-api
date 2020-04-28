#ifndef TGBOT_TYPES_VIDEONOTE_H
#define TGBOT_TYPES_VIDEONOTE_H

#include <string>
#include "tgbot/types/PhotoSize.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct VideoNote
	 */
	struct VideoNote
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<VideoNote> ptr;

		//Member variables
		std::string file_id;
		std::string file_unique_id;
		int length = -1;
		int duration = -1;
		PhotoSize::ptr thumb;
		int file_size = -1;

		//Constructors
		VideoNote();

		//@param json: json object of VideoNote
		VideoNote(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
