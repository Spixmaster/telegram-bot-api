#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORTRANSLATIONFILES_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORTRANSLATIONFILES_H

#include <string>
#include "tgbot/types/PassportElementError.h"
#include <vector>
#include <rapidjson/document.h>
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct PassportElementErrorTranslationFiles : public PassportElementError
	{
		//pointer of itself
		typedef std::shared_ptr<PassportElementErrorTranslationFiles> ptr;

		//member variables
		std::string source;
		std::string type;
		std::vector<std::string> file_hashes;
		std::string message;

		//constructors
		PassportElementErrorTranslationFiles();

		//@param json: json object of PassportElementErrorTranslationFiles
		PassportElementErrorTranslationFiles(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
