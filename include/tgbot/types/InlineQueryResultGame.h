#ifndef TGBOT_TYPES_INLINEQUERYRESULTGAME_H
#define TGBOT_TYPES_INLINEQUERYRESULTGAME_H

#include <string>
#include "tgbot/types/InlineQueryResult.h"
#include "tgbot/types/InlineKeyboardMarkup.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultGame
	 */
	struct InlineQueryResultGame : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultGame> ptr;

		//Member variables
		/**
		 * @var
		 */
		std::string type;
		/**
		 * @var
		 */
		std::string id;
		/**
		 * @var
		 */
		std::string game_short_name;
		/**
		 * @var
		 */
		InlineKeyboardMarkup::ptr reply_markup;

		//Constructors
		InlineQueryResultGame();

		//@param json: json object of InlineQueryResultGame
		InlineQueryResultGame(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
