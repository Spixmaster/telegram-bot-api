#ifndef TGBOT_TYPES_VOICE_H
#define TGBOT_TYPES_VOICE_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct Voice
	 */
	struct Voice
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Voice> ptr;

		//Member variables
		std::string file_id;
		std::string file_unique_id;
		int duration = -1;
		std::string mime_type;
		int file_size = -1;

		//Constructors
		Voice();

		//@param json: json object of Voice
		Voice(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
