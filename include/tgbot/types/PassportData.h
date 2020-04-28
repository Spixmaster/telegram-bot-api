#ifndef TGBOT_TYPES_PASSPORTDATA_H
#define TGBOT_TYPES_PASSPORTDATA_H

#include <vector>
#include "tgbot/types/EncryptedPassportElement.h"
#include "tgbot/types/EncryptedCredentials.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct PassportData
	{
		//pointer of itself
		typedef std::shared_ptr<PassportData> ptr;

		//member variables
		std::vector<EncryptedPassportElement::ptr> data;
		EncryptedCredentials::ptr credentials;

		//constructors
		PassportData();

		//@param json: json object of PassportData
		PassportData(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
