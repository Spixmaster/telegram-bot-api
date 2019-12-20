#ifndef TGBOT_TYPES_INLINEQUERYRESULTGAME_H
#define TGBOT_TYPES_INLINEQUERYRESULTGAME_H

#include <string>
#include "tgbot/types/InlineQueryResult.h"
#include "tgbot/types/InlineKeyboardMarkup.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct InlineQueryResultGame : public InlineQueryResult
	{
		//pointer of itself
		typedef std::shared_ptr<InlineQueryResultGame> ptr;

		//member variables
		std::string type;
		std::string id;
		std::string game_short_name;
		InlineKeyboardMarkup::ptr reply_markup;

		//constructors
		InlineQueryResultGame();

		//@param json: json object of InlineQueryResultGame
		InlineQueryResultGame(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
