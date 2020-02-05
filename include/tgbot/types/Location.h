#ifndef TGBOT_TYPES_LOCATION_H
#define TGBOT_TYPES_LOCATION_H

#include <rapidjson/document.h>
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct Location
	{
		//pointer of itself
		typedef std::shared_ptr<Location> ptr;

		//member variables
		float longitude = -1;
		float latitude = -1;

		//constructors
		Location();

		//@param json: json object of Location
		Location(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
