#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORSELFIE_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORSELFIE_H

#include <string>
#include "PassportElementError.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportElementErrorSelfie
	 */
	struct PassportElementErrorSelfie : public PassportElementError
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PassportElementErrorSelfie> ptr;

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
		PassportElementErrorSelfie();

		//@param json: json object of PassportElementErrorSelfie
		PassportElementErrorSelfie(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
