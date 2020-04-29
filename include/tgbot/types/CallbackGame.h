#ifndef TGBOT_TYPES_CALLBACKGAME_H
#define TGBOT_TYPES_CALLBACKGAME_H

#include <memory>

namespace tgbot
{
	/**
	 * @struct CallbackGame
	 * @brief A placeholder, currently holds no information. Use BotFather to set up your game.
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

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		CallbackGame(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
