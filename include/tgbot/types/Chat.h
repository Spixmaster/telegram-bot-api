#ifndef TGBOT_TYPES_CHAT_H
#define TGBOT_TYPES_CHAT_H

#include <string>
#include "tgbot/types/ChatPhoto.h"
#include "tgbot/types/ChatPermissions.h"
#include <memory>

namespace tgbot
{
	struct Message;

	/**
	 * @struct Chat
	 */
	struct Chat
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Chat> ptr;

		//Member variables
		/**
		 * @var
		 */
		long long id = -1;
		/**
		 * @var
		 */
		std::string type;
		/**
		 * @var
		 */
		std::string title;
		/**
		 * @var
		 */
		std::string username;
		/**
		 * @var
		 */
		std::string first_name;
		/**
		 * @var
		 */
		std::string last_name;
		/**
		 * @var
		 */
		ChatPhoto::ptr photo;
		/**
		 * @var
		 */
		std::string description;
		/**
		 * @var
		 */
		std::string invite_link;
		/**
		 * @var
		 */
		std::shared_ptr<Message> pinned_message;
		/**
		 * @var
		 */
		ChatPermissions::ptr permissions;
		/**
		 * @var
		 */
		int slow_mode_delay = -1;
		/**
		 * @var
		 */
		std::string sticker_set_name;
		/**
		 * @var
		 */
		bool can_set_sticker_set;

		//Constructors
		Chat();

		//@param json: json object of Chat
		Chat(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
