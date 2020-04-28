#ifndef TGBOT_TYPES_CHOSENINLINERESULT_H
#define TGBOT_TYPES_CHOSENINLINERESULT_H

#include <string>
#include "tgbot/types/User.h"
#include "tgbot/types/Location.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct ChosenInlineResult
	 */
	struct ChosenInlineResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<ChosenInlineResult> ptr;

		//Member variables
		std::string result_id;
		User::ptr from;
		Location::ptr location;
		std::string inline_message_id;
		std::string query;

		//Constructors
		ChosenInlineResult();

		//@param json: json object of ChosenInlineResult
		ChosenInlineResult(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
