#ifndef TYPES_INLINEQUERYRESULT_H
#define TYPES_INLINEQUERYRESULT_H

#include <memory>

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
