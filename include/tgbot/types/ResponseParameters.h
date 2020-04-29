#ifndef TGBOT_TYPES_RESPONSEPARAMETERS_H
#define TGBOT_TYPES_RESPONSEPARAMETERS_H

#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct ResponseParameters
	 * @brief Contains information about why a request was unsuccessful.
	 */
	struct ResponseParameters
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<ResponseParameters> ptr;

		//Member variables
		/**
		 * @var migrate_to_chat_id
		 * @brief Optional. The group has been migrated to a supergroup with the specified identifier.
		 * @details This number may be greater than 32 bits and some programming languages may have difficulty/silent defects in interpreting it.
		 * @details But it is smaller than 52 bits, so a signed 64 bit integer or double-precision float type are safe for storing this identifier.
		 */
		int migrate_to_chat_id;
		/**
		 * @var retry_after
		 * @brief Optional. In case of exceeding flood control, the number of seconds left to wait before the request can be repeated
		 */
		int retry_after;

		//Constructors
		ResponseParameters();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		ResponseParameters(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
