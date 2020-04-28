#ifndef TGBOT_TYPES_RESPONSEPARAMETERS_H
#define TGBOT_TYPES_RESPONSEPARAMETERS_H

#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct ResponseParameters
	 */
	struct ResponseParameters
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<ResponseParameters> ptr;

		//Member variables
		/**
		 * @var
		 */
		int migrate_to_chat_id = -1;
		/**
		 * @var
		 */
		int retry_after = -1;

		//Constructors
		ResponseParameters();

		//@param json: json object of ResponseParameters
		ResponseParameters(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
