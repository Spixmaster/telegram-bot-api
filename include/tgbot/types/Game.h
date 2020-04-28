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
		 * @var
		 */
		std::string title;
		/**
		 * @var
		 */
		std::string description;
		/**
		 * @var
		 */
		std::vector<PhotoSize::ptr> photo;
		/**
		 * @var
		 */
		std::string text;
		/**
		 * @var
		 */
		std::vector<MessageEntity::ptr> text_entities;
		/**
		 * @var
		 */
		Animation::ptr animation;

		//Constructors
		Game();

		//@param json: json object of Game
		Game(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
