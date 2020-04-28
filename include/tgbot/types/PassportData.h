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
		std::vector<EncryptedPassportElement::ptr> data;
		EncryptedCredentials::ptr credentials;

		//Constructors
		PassportData();

		//@param json: json object of PassportData
		PassportData(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
