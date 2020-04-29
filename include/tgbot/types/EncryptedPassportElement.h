#ifndef TGBOT_TYPES_ENCRYPTEDPASSPORTELEMENT_H
#define TGBOT_TYPES_ENCRYPTEDPASSPORTELEMENT_H

#include <string>
#include <vector>
#include "tgbot/types/PassportFile.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct EncryptedPassportElement
	 * @brief Contains information about documents or other Telegram Passport elements shared with the bot by the user.
	 */
	struct EncryptedPassportElement
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<EncryptedPassportElement> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Element type. One of “personal_details”, “passport”, “driver_license”, “identity_card”, “internal_passport”, “address”, “utility_bill”, “bank_statement”, “rental_agreement”, “passport_registration”, “temporary_registration”, “phone_number”, “email”.
		 */
		std::string type;
		/**
		 * @var data
		 * @brief Optional. Base64-encoded encrypted Telegram Passport element data provided by the user, available for “personal_details”, “passport”, “driver_license”, “identity_card”, “internal_passport” and “address” types.
		 * @details Can be decrypted and verified using the accompanying EncryptedCredentials.
		 */
		std::string data;
		/**
		 * @var phone_number
		 * @brief Optional. User's verified phone number, available only for “phone_number” type
		 */
		std::string phone_number;
		/**
		 * @var email
		 * @brief Optional. User's verified email address, available only for “email” type
		 */
		std::string email;
		/**
		 * @var files
		 * @brief Optional. Array of encrypted files with documents provided by the user, available for “utility_bill”, “bank_statement”, “rental_agreement”, “passport_registration” and “temporary_registration” types.
		 * @details Files can be decrypted and verified using the accompanying EncryptedCredentials.
		 */
		std::vector<PassportFile::ptr> files;
		/**
		 * @var front_side
		 * @brief Optional. Encrypted file with the front side of the document, provided by the user.
		 * @details Available for “passport”, “driver_license”, “identity_card” and “internal_passport”.
		 * @details The file can be decrypted and verified using the accompanying EncryptedCredentials.
		 */
		PassportFile::ptr front_side;
		/**
		 * @var reverse_side
		 * @brief Optional. Encrypted file with the reverse side of the document, provided by the user.
		 * @details Available for “driver_license” and “identity_card”. The file can be decrypted and verified using the accompanying EncryptedCredentials.
		 */
		PassportFile::ptr reverse_side;
		/**
		 * @var selfie
		 * @brief Optional. Encrypted file with the selfie of the user holding a document, provided by the user; available for “passport”, “driver_license”, “identity_card” and “internal_passport”.
		 * @details The file can be decrypted and verified using the accompanying EncryptedCredentials.
		 */
		PassportFile::ptr selfie;
		/**
		 * @var translation
		 * @brief Optional. Array of encrypted files with translated versions of documents provided by the user. Available if requested for “passport”, “driver_license”, “identity_card”, “internal_passport”, “utility_bill”, “bank_statement”, “rental_agreement”, “passport_registration” and “temporary_registration” types.
		 * @details Files can be decrypted and verified using the accompanying EncryptedCredentials.
		 */
		std::vector<PassportFile::ptr> translation;
		/**
		 * @var hash
		 * @brief Base64-encoded element hash for using in PassportElementErrorUnspecified
		 */
		std::string hash;

		//Constructors
		EncryptedPassportElement();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		EncryptedPassportElement(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}


#endif
