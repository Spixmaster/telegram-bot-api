#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORTRANSLATIONFILE_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORTRANSLATIONFILE_H

#include <string>
#include "tgbot/types/PassportElementError.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	struct PassportElementErrorTranslationFile : public PassportElementError
	{
		//pointer of itself
		typedef std::shared_ptr<PassportElementErrorTranslationFile> ptr;

		//member variables
		std::string source;
		std::string type;
		std::string file_hash;
		std::string message;

		//constructors
		PassportElementErrorTranslationFile();

		//@param json: json object of PassportElementErrorTranslationFile
		PassportElementErrorTranslationFile(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
