#ifndef TGBOT_TYPES_GAMEHIGHSCORE_H
#define TGBOT_TYPES_GAMEHIGHSCORE_H

#include "tgbot/types/User.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct GameHighScore
	 * @brief This object represents one row of the high scores table for a game.
	 */
	struct GameHighScore
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<GameHighScore> ptr;

		//Member variables
		/**
		 * @var position
		 * @brief Position in high score table for the game
		 */
		int position;
		/**
		 * @var user
		 * @brief User
		 */
		User::ptr user;
		/**
		 * @var score
		 * @brief Score
		 */
		int score;

		//Constructors
		GameHighScore();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		GameHighScore(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
