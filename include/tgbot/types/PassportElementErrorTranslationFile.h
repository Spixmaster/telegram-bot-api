#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORTRANSLATIONFILE_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORTRANSLATIONFILE_H

#include <string>
#include "tgbot/types/PassportElementError.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportElementErrorTranslationFile
	 * @brief Represents an issue with one of the files that constitute the translation of a document. The error is considered resolved when the file changes.
	 */
	struct PassportElementErrorTranslationFile : public PassportElementError
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PassportElementErrorTranslationFile> ptr;

		//Member variables
		/**
		 * @var source
		 * @brief Error source, must be translation_file
		 */
		std::string source;
		/**
		 * @var type
		 * @brief Type of element of the user's Telegram Passport which has the issue, one of “passport”, “driver_license”, “identity_card”, “internal_passport”, “utility_bill”, “bank_statement”, “rental_agreement”, “passport_registration”, “temporary_registration”
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
		PassportElementErrorTranslationFile();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		PassportElementErrorTranslationFile(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
