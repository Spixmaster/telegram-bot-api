#ifndef TGBOT_TYPES_INLINEQUERY_H
#define TGBOT_TYPES_INLINEQUERY_H

#include <string>
#include "tgbot/types/User.h"
#include "tgbot/types/Location.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQuery
	 */
	struct InlineQuery
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQuery> ptr;

		//Member variables
		/**
		 * @var
		 */
		std::string id;
		/**
		 * @var
		 */
		User::ptr from;
		/**
		 * @var
		 */
		Location::ptr location;
		/**
		 * @var
		 */
		std::string query;
		/**
		 * @var
		 */
		std::string offset;

		//Constructors
		InlineQuery();

		//@param json: json object of InlineQuery
		InlineQuery(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
