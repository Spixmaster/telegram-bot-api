#ifndef TGBOT_TYPES_VENUE_H
#define TGBOT_TYPES_VENUE_H

#include <string>
#include "tgbot/types/Location.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct Venue
	 * @brief This object represents a venue.
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
		 * @var location
		 * @brief Venue location
		 */
		Location::ptr location;
		/**
		 * @var title
		 * @brief Name of the venue
		 */
		std::string title;
		/**
		 * @var address
		 * @brief Address of the venue
		 */
		std::string address;
		/**
		 * @var foursquare_id
		 * @brief Optional. Foursquare identifier of the venue
		 */
		std::string foursquare_id;
		/**
		 * @var foursquare_type
		 * @brief Optional. Foursquare type of the venue. (For example, “arts_entertainment/default”, “arts_entertainment/aquarium” or “food/icecream”.)
		 */
		std::string foursquare_type;

		//Constructors
		Venue();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		Venue(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
