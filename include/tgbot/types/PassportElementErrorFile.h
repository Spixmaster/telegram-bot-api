#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORFILE_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORFILE_H

#include <string>
#include "PassportElementError.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportElementErrorFile
	 * @brief Represents an issue with a document scan. The error is considered resolved when the file with the document scan changes.
	 */
	struct PassportElementErrorFile : public PassportElementError
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PassportElementErrorFile> ptr;

		//Member variables
		/**
		 * @var source
		 * @brief Error source, must be file
		 */
		std::string source;
		/**
		 * @var type
		 * @brief The section of the user's Telegram Passport which has the issue, one of “utility_bill”, “bank_statement”, “rental_agreement”, “passport_registration”, “temporary_registration”
		 */
		std::string type;
		/**
		 * @var file_hash
		 * @brief Base64-encoded file hash
		 */
		std::string file_hash;
		/**
		 * @var message
		 * @brief Error message
		 */
		std::string message;

		//Constructors
		PassportElementErrorFile();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		PassportElementErrorFile(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
