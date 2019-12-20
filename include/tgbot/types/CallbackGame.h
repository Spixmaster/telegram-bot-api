#ifndef TGBOT_TYPES_CALLBACKGAME_H
#define TGBOT_TYPES_CALLBACKGAME_H

#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct CallbackGame
	{
		//pointer of itself
		typedef std::shared_ptr<CallbackGame> ptr;

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
