#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORDATAFIELD_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORDATAFIELD_H

#include <string>
#include "tgbot/types/PassportElementError.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportElementErrorDataField
	 * @brief Represents an issue in one of the data fields that was provided by the user. The error is considered resolved when the field's value changes.
	 */
	struct PassportElementErrorDataField : public PassportElementError
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PassportElementErrorDataField> ptr;

		//Member variables
		/**
		 * @var source
		 * @brief Error source, must be data
		 */
		std::string source;
		/**
		 * @var type
		 * @brief The section of the user's Telegram Passport which has the error, one of “personal_details”, “passport”, “driver_license”, “identity_card”, “internal_passport”, “address”
		 */
		std::string type;
		/**
		 * @var field_name
		 * @brief Name of the data field which has the error
		 */
		std::string field_name;
		/**
		 * @var data_hash
		 * @brief Base64-encoded data hash
		 */
		std::string data_hash;
		/**
		 * @var message
		 * @brief Error message
		 */
		std::string message;

		//Constructors
		PassportElementErrorDataField();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		PassportElementErrorDataField(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
