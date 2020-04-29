#ifndef TGBOT_TYPES_ENCRYPTEDCREDENTIALS_H
#define TGBOT_TYPES_ENCRYPTEDCREDENTIALS_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct EncryptedCredentials
	 * @brief Contains data required for decrypting and authenticating EncryptedPassportElement.
	 * @details See the Telegram Passport Documentation for a complete description of the data decryption and authentication processes.
	 */
	struct EncryptedCredentials
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<EncryptedCredentials> ptr;

		//Member variables
		/**
		 * @var data
		 * @brief Base64-encoded encrypted JSON-serialized data with unique user's payload, data hashes and secrets required for EncryptedPassportElement decryption and authentication
		 */
		std::string data;
		/**
		 * @var hash
		 * @brief Base64-encoded data hash for data authentication
		 */
		std::string hash;
		/**
		 * @var secret
		 * @brief Base64-encoded secret, encrypted with the bot's public RSA key, required for data decryption
		 */
		std::string secret;

		//Constructors
		EncryptedCredentials();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		EncryptedCredentials(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
