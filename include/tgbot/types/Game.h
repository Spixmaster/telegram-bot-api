#ifndef TGBOT_TYPES_GAME_H
#define TGBOT_TYPES_GAME_H

#include <string>
#include <vector>
#include "tgbot/types/PhotoSize.h"
#include "tgbot/types/MessageEntity.h"
#include "tgbot/types/Animation.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct Game
	 * @brief This object represents a game. Use BotFather to create and edit games, their short names will act as unique identifiers.
	 */
	struct Game
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Game> ptr;

		//Member variables
		/**
		 * @var title
		 * @brief Title of the game
		 */
		std::string title;
		/**
		 * @var description
		 * @brief Description of the game
		 */
		std::string description;
		/**
		 * @var photo
		 * @brief Photo that will be displayed in the game message in chats.
		 */
		std::vector<PhotoSize::ptr> photo;
		/**
		 * @var text
		 * @brief Optional. Brief description of the game or high scores included in the game message.
		 * @details Can be automatically edited to include current high scores for the game when the bot calls setGameScore, or manually edited using editMessageText.
		 * @details 0-4096 characters.
		 */
		std::string text;
		/**
		 * @var text_entities
		 * @brief Optional. Special entities that appear in text, such as usernames, URLs, bot commands, etc.
		 */
		std::vector<MessageEntity::ptr> text_entities;
		/**
		 * @var animation
		 * @brief Optional. Animation that will be displayed in the game message in chats. Upload via BotFather
		 */
		Animation::ptr animation;

		//Constructors
		Game();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		Game(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
