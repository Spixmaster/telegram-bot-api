#ifndef TGBOT_TYPES_INLINEQUERYRESULTLOCATION_H
#define TGBOT_TYPES_INLINEQUERYRESULTLOCATION_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultLocation
	 * @brief Represents a location on a map.
	 * @details By default, the location will be sent by the user.
	 * @details Alternatively, you can use input_message_content to send a message with the specified content instead of the location.
	 * @note This will only work in Telegram versions released after 9 April, 2016. Older clients will ignore them.
	 */
	struct InlineQueryResultLocation : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultLocation> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the result, must be location
		 */
		const std::string type = "location";
		/**
		 * @var id
		 * @brief Unique identifier for this result, 1-64 Bytes
		 */
		std::string id;
		/**
		 * @var latitude
		 * @brief Location latitude in degrees
		 */
		float latitude = -1;
		/**
		 * @var longitude
		 * @brief Location longitude in degrees
		 */
		float longitude = -1;
		/**
		 * @var title
		 * @brief Location title
		 */
		std::string title;
		/**
		 * @var live_period
		 * @brief Optional. Period in seconds for which the location can be updated, should be between 60 and 86400.
		 */
		int live_period = -1;
		/**
		 * @var reply_markup
		 * @brief Optional. Inline keyboard attached to the message
		 */
		InlineKeyboardMarkup::ptr reply_markup;
		/**
		 * @var input_message_content
		 * @brief Optional. Content of the message to be sent instead of the location
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
		int thumb_width = -1;
		/**
		 * @var thumb_height
		 * @brief Optional. Thumbnail height
		 */
		int thumb_height = -1;

		//Constructors
		InlineQueryResultLocation();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQueryResultLocation(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
