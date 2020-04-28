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
		long long id = -1;
		std::string type;
		std::string title;
		std::string username;
		std::string first_name;
		std::string last_name;
		ChatPhoto::ptr photo;
		std::string description;
		std::string invite_link;
		std::shared_ptr<Message> pinned_message;
		ChatPermissions::ptr permissions;
		int slow_mode_delay = -1;
		std::string sticker_set_name;
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
