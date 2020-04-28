#ifndef TGBOT_TYPES_LOCATION_H
#define TGBOT_TYPES_LOCATION_H

#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct Location
	 */
	struct Location
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Location> ptr;

		//Member variables
		/**
		 * @var
		 */
		float longitude = -1;
		/**
		 * @var
		 */
		float latitude = -1;

		//Constructors
		Location();

		//@param json: json object of Location
		Location(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
