#ifndef TGBOT_TYPES_ENCRYPTEDPASSPORTELEMENT_H
#define TGBOT_TYPES_ENCRYPTEDPASSPORTELEMENT_H

#include <string>
#include <vector>
#include "tgbot/types/PassportFile.h"
#include "tgbot/special_tools.h"
#include <memory>

namespace tgbot
{
	struct EncryptedPassportElement
	{
		//pointer of itself
		typedef std::shared_ptr<EncryptedPassportElement> ptr;

		//member variables
		std::string type;
		std::string data;
		std::string phone_number;
		std::string email;
		std::vector<PassportFile::ptr> files;
		PassportFile::ptr front_side;
		PassportFile::ptr reverse_side;
		PassportFile::ptr selfie;
		std::vector<PassportFile::ptr> translation;
		std::string hash;

		//constructors
		EncryptedPassportElement();

		//@param json: json object of EncryptedPassportElement
		EncryptedPassportElement(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}


#endif
