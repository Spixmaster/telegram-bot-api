#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORUNSPECIFIED_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORUNSPECIFIED_H

#include <string>
#include "PassportElementError.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	struct PassportElementErrorUnspecified : public PassportElementError
	{
		//pointer of itself
		typedef std::shared_ptr<PassportElementErrorUnspecified> ptr;

		//member variables
		std::string source;
		std::string type;
		std::string element_hash;
		std::string message;

		//constructors
		PassportElementErrorUnspecified();

		//@param json: json object of PassportElementErrorUnspecified
		PassportElementErrorUnspecified(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
