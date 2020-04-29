#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORUNSPECIFIED_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORUNSPECIFIED_H

#include <string>
#include "PassportElementError.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportElementErrorUnspecified
	 * @brief Represents an issue in an unspecified place. The error is considered resolved when new data is added.
	 */
	struct PassportElementErrorUnspecified : public PassportElementError
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PassportElementErrorUnspecified> ptr;

		//Member variables
		/**
		 * @var source
		 * @brief Error source, must be unspecified
		 */
		std::string source;
		/**
		 * @var type
		 * @brief Type of element of the user's Telegram Passport which has the issue
		 */
		std::string type;
		/**
		 * @var element_hash
		 * @brief Base64-encoded element hash
		 */
		std::string element_hash;
		/**
		 * @var message
		 * @brief Error message
		 */
		std::string message;

		//Constructors
		PassportElementErrorUnspecified();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		PassportElementErrorUnspecified(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
