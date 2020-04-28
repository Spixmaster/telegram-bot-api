#ifndef TGBOT_TYPES_ENCRYPTEDCREDENTIALS_H
#define TGBOT_TYPES_ENCRYPTEDCREDENTIALS_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct EncryptedCredentials
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
		 * @var
		 */
		std::string data;
		/**
		 * @var
		 */
		std::string hash;
		/**
		 * @var
		 */
		std::string secret;

		//Constructors
		EncryptedCredentials();

		//@param json: json object of EncryptedCredentials
		EncryptedCredentials(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
