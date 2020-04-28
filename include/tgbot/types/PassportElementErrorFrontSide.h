#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORFRONTSIDE_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORFRONTSIDE_H

#include <string>
#include "PassportElementError.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportElementErrorFrontSide
	 */
	struct PassportElementErrorFrontSide : public PassportElementError
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PassportElementErrorFrontSide> ptr;

		//Member variables
		std::string source;
		std::string type;
		std::string file_hash;
		std::string message;

		//Constructors
		PassportElementErrorFrontSide();

		//@param json: json object of PassportElementErrorFrontSide
		PassportElementErrorFrontSide(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
