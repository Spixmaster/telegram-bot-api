#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORUNSPECIFIED_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORUNSPECIFIED_H

#include <string>
#include "PassportElementError.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportElementErrorUnspecified
	 */
	struct PassportElementErrorUnspecified : public PassportElementError
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PassportElementErrorUnspecified> ptr;

		//Member variables
		std::string source;
		std::string type;
		std::string element_hash;
		std::string message;

		//Constructors
		PassportElementErrorUnspecified();

		//@param json: json object of PassportElementErrorUnspecified
		PassportElementErrorUnspecified(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
