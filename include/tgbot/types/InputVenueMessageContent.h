#ifndef TGBOT_TYPES_INPUTVENUEMESSAGECONTENT_H
#define TGBOT_TYPES_INPUTVENUEMESSAGECONTENT_H

#include <string>
#include "tgbot/types/InputMessageContent.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct InputVenueMessageContent
	 * @brief Represents the content of a venue message to be sent as the result of an inline query.
	 */
	struct InputVenueMessageContent : public InputMessageContent
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InputVenueMessageContent> ptr;

		//Member variables
		/**
		 * @var latitude
		 * @brief Latitude of the venue in degrees
		 */
		float latitude;
		/**
		 * @var longitude
		 * @brief Longitude of the venue in degrees
		 */
		float longitude;
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
		 * @brief Optional. Foursquare identifier of the venue, if known
		 */
		std::string foursquare_id;
		/**
		 * @var foursquare_type
		 * @brief Optional. Foursquare type of the venue, if known. (For example, “arts_entertainment/default”, “arts_entertainment/aquarium” or “food/icecream”.)
		 */
		std::string foursquare_type;

		//Constructors
		InputVenueMessageContent();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InputVenueMessageContent(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
