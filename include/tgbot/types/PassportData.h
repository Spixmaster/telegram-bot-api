#ifndef TGBOT_TYPES_PASSPORTDATA_H
#define TGBOT_TYPES_PASSPORTDATA_H

#include <vector>
#include "tgbot/types/EncryptedPassportElement.h"
#include "tgbot/types/EncryptedCredentials.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportData
	 * @brief Contains information about Telegram Passport data shared with the bot by the user.
	 */
	struct PassportData
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PassportData> ptr;

		//Member variables
		/**
		 * @var data
		 * @brief Array with information about documents and other Telegram Passport elements that was shared with the bot
		 */
		std::vector<EncryptedPassportElement::ptr> data;
		/**
		 * @var credentials
		 * @brief Encrypted credentials required to decrypt the data
		 */
		EncryptedCredentials::ptr credentials;

		//Constructors
		PassportData();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		PassportData(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
