#ifndef TGBOT_TYPES_GAME_H
#define TGBOT_TYPES_GAME_H

#include <string>
#include <vector>
#include "tgbot/types/PhotoSize.h"
#include "tgbot/types/MessageEntity.h"
#include "tgbot/types/Animation.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct Game
	{
		//pointer of itself
		typedef std::shared_ptr<Game> ptr;

		//member variables
		std::string title;
		std::string description;
		std::vector<PhotoSize::ptr> photo;
		std::string text;
		std::vector<MessageEntity::ptr> text_entities;
		Animation::ptr animation;

		//constructors
		Game();

		//@param json: json object of Game
		Game(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
