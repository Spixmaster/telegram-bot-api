#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORFRONTSIDE_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORFRONTSIDE_H

#include <string>
#include "PassportElementError.h"
#include <rapidjson/document.h>
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct PassportElementErrorFrontSide : public PassportElementError
	{
		//pointer of itself
		typedef std::shared_ptr<PassportElementErrorFrontSide> ptr;

		//member variables
		std::string source;
		std::string type;
		std::string file_hash;
		std::string message;

		//constructors
		PassportElementErrorFrontSide();

		//@param json: json object of PassportElementErrorFrontSide
		PassportElementErrorFrontSide(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
