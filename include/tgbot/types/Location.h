#ifndef TGBOT_TYPES_LOCATION_H
#define TGBOT_TYPES_LOCATION_H

#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct Location
	 * @brief This object represents a point on the map.
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
		 * @var longitude
		 * @brief Longitude as defined by sender
		 */
		float longitude = -1;
		/**
		 * @var latitude
		 * @brief Latitude as defined by sender
		 */
		float latitude = -1;

		//Constructors
		Location();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		Location(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
