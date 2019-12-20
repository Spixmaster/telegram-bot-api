#ifndef TGBOT_TYPES_INLINEQUERYRESULT_H
#define TGBOT_TYPES_INLINEQUERYRESULT_H

#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct InlineQueryResult
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQueryResult> ptr;

		//destructors
		virtual ~InlineQueryResult();

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		virtual std::string parse_to_json() const;
	};
}

#endif
