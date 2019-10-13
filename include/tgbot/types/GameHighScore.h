#ifndef TGBOT_TYPES_GAMEHIGHSCORE_H
#define TGBOT_TYPES_GAMEHIGHSCORE_H

#include "tgbot/types/User.h"
#include <rapidjson/document.h>
#include "tgbot/SpecialTools.h"
#include <memory>

namespace tgbot
{
	struct GameHighScore
	{
		//pointer of itself
		typedef std::shared_ptr<GameHighScore> ptr;

		//member variables
		int position = -1;
		User::ptr user;
		int score = -1;

		//constructors
		GameHighScore();

		//@param json: json object of GameHighScore
		GameHighScore(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
