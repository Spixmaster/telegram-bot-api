#ifndef TYPES_CALLBACKGAME_H
#define TYPES_CALLBACKGAME_H

#include <memory>

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
