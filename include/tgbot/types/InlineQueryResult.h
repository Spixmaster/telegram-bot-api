#ifndef TGBOT_TYPES_INLINEQUERYRESULT_H
#define TGBOT_TYPES_INLINEQUERYRESULT_H

#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResult
	 * @brief This object represents one result of an inline query. Telegram clients currently support results of the following 20 types: ...
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
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		virtual std::string parse_to_json() const noexcept;
	};
}

#endif
