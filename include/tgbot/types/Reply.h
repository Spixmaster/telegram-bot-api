#ifndef TGBOT_TYPES_REPLY_H
#define TGBOT_TYPES_REPLY_H

#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct Reply
	{
		//pointer of itself
		typedef std::shared_ptr<Reply> ptr;

		//destructors
		virtual ~Reply();

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		virtual std::string parse_to_json() const noexcept;
	};
}

#endif
