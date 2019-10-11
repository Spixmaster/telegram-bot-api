#ifndef TYPES_RESPONSEPARAMETERS_H
#define TYPES_RESPONSEPARAMETERS_H

#include <rapidjson/document.h>
#include "tgbot/special_tools.h"
#include <memory>

namespace tgbot
{
	struct ResponseParameters
	{
		//pointer of itself
		typedef std::shared_ptr<ResponseParameters> ptr;

		//member variables
		int migrate_to_chat_id = -1;
		int retry_after = -1;

		//constructors
		ResponseParameters();

		//@param json: json object of ResponseParameters
		ResponseParameters(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
