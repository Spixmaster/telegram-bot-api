#ifndef TGBOT_TYPES_INLINEQUERYRESULT_H
#define TGBOT_TYPES_INLINEQUERYRESULT_H

#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResult
	 */
	struct InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResult> ptr;

		//Destructors
		virtual ~InlineQueryResult();

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		virtual std::string parse_to_json() const noexcept;
	};
}

#endif
