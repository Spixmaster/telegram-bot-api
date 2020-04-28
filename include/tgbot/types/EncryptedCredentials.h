#ifndef TGBOT_TYPES_ENCRYPTEDCREDENTIALS_H
#define TGBOT_TYPES_ENCRYPTEDCREDENTIALS_H

#include <string>
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct EncryptedCredentials
	{
		//pointer of itself
		typedef std::shared_ptr<EncryptedCredentials> ptr;

		//member variables
		std::string data;
		std::string hash;
		std::string secret;

		//constructors
		EncryptedCredentials();

		//@param json: json object of EncryptedCredentials
		EncryptedCredentials(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
