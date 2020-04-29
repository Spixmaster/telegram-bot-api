#ifndef TGBOT_TYPES_INLINEQUERYRESULTVENUE_H
#define TGBOT_TYPES_INLINEQUERYRESULTVENUE_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultVenue
	 * @brief Represents a venue.
	 * @details By default, the venue will be sent by the user.
	 * @details Alternatively, you can use input_message_content to send a message with the specified content instead of the venue.
	 * @note This will only work in Telegram versions released after 9 April, 2016. Older clients will ignore them.
	 */
	struct InlineQueryResultVenue : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultVenue> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the result, must be venue
		 */
		std::string type;
		/**
		 * @var id
		 * @brief Unique identifier for this result, 1-64 Bytes
		 */
		std::string id;
		/**
		 * @var latitude
		 * @brief Latitude of the venue location in degrees
		 */
		float latitude;
		/**
		 * @var longitude
		 * @brief Longitude of the venue location in degrees
		 */
		float longitude;
		/**
		 * @var title
		 * @brief Title of the venue
		 */
		std::string title;
		/**
		 * @var address
		 * @brief Address of the venue
		 */
		std::string address;
		/**
		 * @var foursquare_id
		 * @brief Optional. Foursquare identifier of the venue if known
		 */
		std::string foursquare_id;
		/**
		 * @var foursquare_type
		 * @brief Optional. Foursquare type of the venue, if known. (For example, “arts_entertainment/default”, “arts_entertainment/aquarium” or “food/icecream”.)
		 */
		std::string foursquare_type;
		/**
		 * @var reply_markup
		 * @brief Optional. Inline keyboard attached to the message
		 */
		InlineKeyboardMarkup::ptr reply_markup;
		/**
		 * @var input_message_content
		 * @brief Optional. Content of the message to be sent instead of the venue
		 */
		InputMessageContent::ptr input_message_content;
		/**
		 * @var thumb_url
		 * @brief Optional. Url of the thumbnail for the result
		 */
		std::string thumb_url;
		/**
		 * @var thumb_width
		 * @brief Optional. Thumbnail width
		 */
		int thumb_width;
		/**
		 * @var thumb_height
		 * @brief Optional. Thumbnail height
		 */
		int thumb_height;

		//Constructors
		InlineQueryResultVenue();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQueryResultVenue(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
