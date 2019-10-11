#ifndef TYPES_CHATPERMISSIONS_H
#define TYPES_CHATPERMISSIONS_H

#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	struct ChatPermissions
	{
		//pointer of itself
		typedef std::shared_ptr<ChatPermissions> ptr;

		//member variables
		bool can_send_messages;
		bool can_send_media_messages;
		bool can_send_polls;
		bool can_send_other_messages;
		bool can_add_web_page_preview;
		bool can_change_info;
		bool can_invite_users;
		bool can_pin_messages;

		//constructors
		ChatPermissions();

		//@param json: json object of ChatPermissions
		ChatPermissions(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json();
	};
}

#endif
