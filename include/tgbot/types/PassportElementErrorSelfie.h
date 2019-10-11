#ifndef TYPES_PASSPORTELEMENTERRORSELFIE_H
#define TYPES_PASSPORTELEMENTERRORSELFIE_H

#include <string>
#include "PassportElementError.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	struct PassportElementErrorSelfie : public PassportElementError
	{
		//pointer of itself
		typedef std::shared_ptr<PassportElementErrorSelfie> ptr;

		//member variables
		std::string source;
		std::string type;
		std::string file_hash;
		std::string message;

		//constructors
		PassportElementErrorSelfie();

		//@param json: json object of PassportElementErrorSelfie
		PassportElementErrorSelfie(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
