#ifndef TGBOT_TYPES_INPUTLOCATIONMESSAGECONTENT_H
#define TGBOT_TYPES_INPUTLOCATIONMESSAGECONTENT_H

#include "tgbot/types/InputMessageContent.h"
#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct InputLocationMessageContent
	 * @brief Represents the content of a location message to be sent as the result of an inline query.
	 */
	struct InputLocationMessageContent : public InputMessageContent
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InputLocationMessageContent> ptr;

		//Member variables
		/**
		 * @var latitude
		 * @brief Latitude of the location in degrees
		 */
		float latitude;
		/**
		 * @var longitude
		 * @brief Longitude of the location in degrees
		 */
		float longitude;
		/**
		 * @var live_period
		 * @brief Optional. Period in seconds for which the location can be updated, should be between 60 and 86400.
		 */
		int live_period;

		//Constructors
		InputLocationMessageContent();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InputLocationMessageContent(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
