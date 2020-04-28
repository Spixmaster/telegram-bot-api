#ifndef TGBOT_TYPES_VENUE_H
#define TGBOT_TYPES_VENUE_H

#include <string>
#include "tgbot/types/Location.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct Venue
	 */
	struct Venue
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Venue> ptr;

		//Member variables
		/**
		 * @var
		 */
		Location::ptr location;
		/**
		 * @var
		 */
		std::string title;
		/**
		 * @var
		 */
		std::string address;
		/**
		 * @var
		 */
		std::string foursquare_id;
		/**
		 * @var
		 */
		std::string foursquare_type;

		//Constructors
		Venue();

		//@param json: json object of Venue
		Venue(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
