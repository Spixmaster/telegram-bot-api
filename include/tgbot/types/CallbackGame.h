#ifndef TGBOT_TYPES_CALLBACKGAME_H
#define TGBOT_TYPES_CALLBACKGAME_H

#include <memory>

namespace tgbot
{
	/**
	 * @struct CallbackGame
	 */
	struct CallbackGame
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<CallbackGame> ptr;

		//Constructors
		CallbackGame();

		//@param json: json object of CallbackGame
		CallbackGame(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
