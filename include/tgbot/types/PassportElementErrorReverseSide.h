#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORREVERSESIDE_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORREVERSESIDE_H

#include <string>
#include "tgbot/types/PassportElementError.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportElementErrorReverseSide
	 * @brief Represents an issue with the reverse side of a document. The error is considered resolved when the file with reverse side of the document changes.
	 */
	struct PassportElementErrorReverseSide : public PassportElementError
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PassportElementErrorReverseSide> ptr;

		//Member variables
		/**
		 * @var source
		 * @brief Error source, must be reverse_side
		 */
		std::string source;
		/**
		 * @var type
		 * @brief The section of the user's Telegram Passport which has the issue, one of “driver_license”, “identity_card”
		 */
		std::string type;
		/**
		 * @var file_hash
		 * @brief Base64-encoded hash of the file with the reverse side of the document
		 */
		std::string file_hash;
		/**
		 * @var message
		 * @brief Error message
		 */
		std::string message;

		//Constructors
		PassportElementErrorReverseSide();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		PassportElementErrorReverseSide(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
