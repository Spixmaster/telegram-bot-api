#ifndef TYPES_VOICE_H
#define TYPES_VOICE_H

#include <string>
#include <memory>

namespace tgbot
{
	struct Voice
	{
		//pointer of itself
		typedef std::shared_ptr<Voice> ptr;

		//member variables
		std::string file_id;
		int duration = -1;
		std::string mime_type;
		int file_size = -1;

		//constructors
		Voice();

		//@param json: json object of Voice
		Voice(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
