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
		/**
		 * @var
		 */
		std::string type;
		/**
		 * @var
		 */
		std::string data;
		/**
		 * @var
		 */
		std::string phone_number;
		/**
		 * @var
		 */
		std::string email;
		/**
		 * @var
		 */
		std::vector<PassportFile::ptr> files;
		/**
		 * @var
		 */
		PassportFile::ptr front_side;
		/**
		 * @var
		 */
		PassportFile::ptr reverse_side;
		/**
		 * @var
		 */
		PassportFile::ptr selfie;
		/**
		 * @var
		 */
		std::vector<PassportFile::ptr> translation;
		/**
		 * @var
		 */
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
