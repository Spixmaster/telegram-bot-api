#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORDATAFIELD_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORDATAFIELD_H

#include <string>
#include "tgbot/types/PassportElementError.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportElementErrorDataField
	 */
	struct PassportElementErrorDataField : public PassportElementError
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PassportElementErrorDataField> ptr;

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
		std::string field_name;
		/**
		 * @var
		 */
		std::string data_hash;
		/**
		 * @var
		 */
		std::string message;

		//Constructors
		PassportElementErrorDataField();

		//@param json: json object of PassportElementErrorDataField
		PassportElementErrorDataField(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
