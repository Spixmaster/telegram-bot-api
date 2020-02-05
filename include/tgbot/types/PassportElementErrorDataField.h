#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORDATAFIELD_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORDATAFIELD_H

#include <string>
#include "tgbot/types/PassportElementError.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct PassportElementErrorDataField : public PassportElementError
	{
		//pointer of itself
		typedef std::shared_ptr<PassportElementErrorDataField> ptr;

		//member variables
		std::string source;
		std::string type;
		std::string field_name;
		std::string data_hash;
		std::string message;

		//constructors
		PassportElementErrorDataField();

		//@param json: json object of PassportElementErrorDataField
		PassportElementErrorDataField(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
