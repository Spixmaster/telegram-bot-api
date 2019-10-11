#ifndef TGBOT_TYPES_CHATMEMBER_H
#define TGBOT_TYPES_CHATMEMBER_H

#include <string>
#include "tgbot/types/User.h"
#include "tgbot/special_tools.h"
#include <memory>

namespace tgbot
{
	struct ChatMember
	{
		//pointer of itself
		typedef std::shared_ptr<ChatMember> ptr;

		//member variables
		User::ptr user;
		std::string status;
		int until_date = -1;
		bool can_be_edited;
		bool can_post_messages;
		bool can_edit_messages;
		bool can_delete_messages;
		bool can_restrict_members;
		bool can_promote_members;
		bool can_change_info;
		bool can_invite_users;
		bool is_member;
		bool can_send_messages;
		bool can_send_media_messages;
		bool can_send_polls;
		bool can_send_other_messages;
		bool can_add_web_page_previews;

		//constructors
		ChatMember();

		//@param json: json object of ChatMember
		ChatMember(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
