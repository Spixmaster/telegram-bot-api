#ifndef TGBOT_TYPES_GAMEHIGHSCORE_H
#define TGBOT_TYPES_GAMEHIGHSCORE_H

#include "tgbot/types/User.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct GameHighScore
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
		 * @var
		 */
		int position = -1;
		/**
		 * @var
		 */
		User::ptr user;
		/**
		 * @var
		 */
		int score = -1;

		//Constructors
		GameHighScore();

		//@param json: json object of GameHighScore
		GameHighScore(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
