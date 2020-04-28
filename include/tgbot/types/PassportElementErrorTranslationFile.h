#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORTRANSLATIONFILE_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORTRANSLATIONFILE_H

#include <string>
#include "tgbot/types/PassportElementError.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportElementErrorTranslationFile
	 */
	struct PassportElementErrorTranslationFile : public PassportElementError
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PassportElementErrorTranslationFile> ptr;

		//Member variables
		/**
		 * @var
		 */
		std::string source;
		/**
		 * @var
		 */
		std::string type;
		/**
		 * @var
		 */
		std::string file_hash;
		/**
		 * @var
		 */
		std::string message;

		//Constructors
		PassportElementErrorTranslationFile();

		//@param json: json object of PassportElementErrorTranslationFile
		PassportElementErrorTranslationFile(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
