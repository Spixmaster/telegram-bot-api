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
	 * @brief Represents a Game.
	 * @note This will only work in Telegram versions released after October 1, 2016. Older clients will not display any inline results if a game result is among them.
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
		 * @var type
		 * @brief Type of the result, must be game
		 */
		const std::string type = "game";
		/**
		 * @var id
		 * @brief Unique identifier for this result, 1-64 bytes
		 */
		std::string id;
		/**
		 * @var game_short_name
		 * @brief Short name of the game
		 */
		std::string game_short_name;
		/**
		 * @var reply_markup
		 * @brief Optional. Inline keyboard attached to the message
		 */
		InlineKeyboardMarkup::ptr reply_markup;

		//Constructors
		InlineQueryResultGame();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQueryResultGame(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
