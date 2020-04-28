#ifndef TGBOT_TYPES_PASSPORTELEMENTERRORFILES_H
#define TGBOT_TYPES_PASSPORTELEMENTERRORFILES_H

#include <string>
#include "tgbot/types/PassportElementError.h"
#include <vector>
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportElementErrorFiles
	 */
	struct PassportElementErrorFiles : public PassportElementError
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PassportElementErrorFiles> ptr;

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
		std::vector<std::string> file_hashes;
		/**
		 * @var
		 */
		std::string message;

		//Constructors
		PassportElementErrorFiles();

		//@param json: json object of PassportElementErrorFiles
		PassportElementErrorFiles(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
