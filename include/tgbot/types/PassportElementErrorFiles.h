#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORFILES_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORFILES_H

#include <string>
#include "tgbot/types/PassportElementError.h"
#include <vector>
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportElementErrorFiles
	 * @brief Represents an issue with a list of scans. The error is considered resolved when the list of files containing the scans changes.
	 */
	struct PassportElementErrorFiles : public PassportElementError
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PassportElementErrorFiles> ptr;

		//Member variables
		/**
		 * @var source
		 * @brief Error source, must be files
		 */
		std::string source;
		/**
		 * @var type
		 * @brief The section of the user's Telegram Passport which has the issue, one of “utility_bill”, “bank_statement”, “rental_agreement”, “passport_registration”, “temporary_registration”
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
		PassportElementErrorFiles();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		PassportElementErrorFiles(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
