#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORSELFIE_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORSELFIE_H

#include <string>
#include "PassportElementError.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportElementErrorSelfie
	 * @brief Represents an issue with the selfie with a document. The error is considered resolved when the file with the selfie changes.
	 */
	struct PassportElementErrorSelfie : public PassportElementError
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PassportElementErrorSelfie> ptr;

		//Member variables
		/**
		 * @var source
		 * @brief Error source, must be selfie
		 */
		std::string source;
		/**
		 * @var type
		 * @brief The section of the user's Telegram Passport which has the issue, one of “passport”, “driver_license”, “identity_card”, “internal_passport”
		 */
		std::string type;
		/**
		 * @var file_hash
		 * @brief Base64-encoded hash of the file with the selfie
		 */
		std::string file_hash;
		/**
		 * @var message
		 * @brief Error message
		 */
		std::string message;

		//Constructors
		PassportElementErrorSelfie();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		PassportElementErrorSelfie(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
