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
		int length = -1;
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
