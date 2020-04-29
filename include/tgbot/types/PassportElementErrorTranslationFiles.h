#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORTRANSLATIONFILES_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORTRANSLATIONFILES_H

#include <string>
#include "tgbot/types/PassportElementError.h"
#include <vector>
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportElementErrorTranslationFiles
	 * @brief Represents an issue with the translated version of a document. The error is considered resolved when a file with the document translation change.
	 */
	struct PassportElementErrorTranslationFiles : public PassportElementError
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PassportElementErrorTranslationFiles> ptr;

		//Member variables
		/**
		 * @var source
		 * @brief Error source, must be translation_files
		 */
		std::string source;
		/**
		 * @var type
		 * @brief Type of element of the user's Telegram Passport which has the issue, one of “passport”, “driver_license”, “identity_card”, “internal_passport”, “utility_bill”, “bank_statement”, “rental_agreement”, “passport_registration”, “temporary_registration”
		 */
		std::string type;
		/**
		 * @var file_hashes
		 * @brief List of base64-encoded file hashes
		 */
		std::vector<std::string> file_hashes;
		/**
		 * @var message
		 * @brief Error message
		 */
		std::string message;

		//Constructors
		PassportElementErrorTranslationFiles();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		PassportElementErrorTranslationFiles(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
