#ifndef TYPES_PASSPORTELEMENTERRORFILE_H
#define TYPES_PASSPORTELEMENTERRORFILE_H

#include <string>
#include "PassportElementError.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	struct PassportElementErrorFile : public PassportElementError
	{
		//pointer of itself
		typedef std::shared_ptr<PassportElementErrorFile> ptr;

		//member variables
		std::string source;
		std::string type;
		std::string file_hash;
		std::string message;

		//constructors
		PassportElementErrorFile();

		//@param json: json object of PassportElementErrorFile
		PassportElementErrorFile(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
