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

		//Constructors
		EncryptedPassportElement();

		//@param json: json object of EncryptedPassportElement
		EncryptedPassportElement(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}


#endif
