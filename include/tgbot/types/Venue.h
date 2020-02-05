#ifndef TGBOT_TYPES_VENUE_H
#define TGBOT_TYPES_VENUE_H

#include <string>
#include "tgbot/types/Location.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct Venue
	{
		//pointer of itself
		typedef std::shared_ptr<Venue> ptr;

		//member variables
		Location::ptr location;
		std::string title;
		std::string address;
		std::string foursquare_id;
		std::string foursquare_type;

		//constructors
		Venue();

		//@param json: json object of Venue
		Venue(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
