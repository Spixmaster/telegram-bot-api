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
	 * @brief This object represents an incoming inline query.
	 * @details When the user sends an empty query, your bot could return some default or trending results.
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
		 * @var id
		 * @brief Unique identifier for this query
		 */
		std::string id;
		/**
		 * @var from
		 * @brief Sender
		 */
		User::ptr from;
		/**
		 * @var location
		 * @brief Optional. Sender location, only for bots that request user location
		 */
		Location::ptr location;
		/**
		 * @var query
		 * @brief Text of the query (up to 256 characters)
		 */
		std::string query;
		/**
		 * @var offset
		 * @brief Offset of the results to be returned, can be controlled by the bot
		 */
		std::string offset;

		//Constructors
		InlineQuery();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQuery(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
