#ifndef TGBOT_TYPES_CHATMEMBER_H
#define TGBOT_TYPES_CHATMEMBER_H

#include <string>
#include "tgbot/types/User.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct ChatMember
	 */
	struct ChatMember
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<ChatMember> ptr;

		//Member variables
		/**
		 * @var
		 */
		User::ptr user;
		/**
		 * @var
		 */
		std::string status;
		/**
		 * @var
		 */
		std::string custom_title;
		/**
		 * @var
		 */
		int until_date = -1;
		/**
		 * @var
		 */
		bool can_be_edited;
		/**
		 * @var
		 */
		bool can_post_messages;
		/**
		 * @var
		 */
		bool can_edit_messages;
		/**
		 * @var
		 */
		bool can_delete_messages;
		/**
		 * @var
		 */
		bool can_restrict_members;
		/**
		 * @var
		 */
		bool can_promote_members;
		/**
		 * @var
		 */
		bool can_change_info;
		/**
		 * @var
		 */
		bool can_invite_users;
		/**
		 * @var
		 */
		bool can_pin_messages;
		/**
		 * @var
		 */
		bool is_member;
		/**
		 * @var
		 */
		bool can_send_messages;
		/**
		 * @var
		 */
		bool can_send_media_messages;
		/**
		 * @var
		 */
		bool can_send_polls;
		/**
		 * @var
		 */
		bool can_send_other_messages;
		/**
		 * @var
		 */
		bool can_add_web_page_previews;

		//Constructors
		ChatMember();

		//@param json: json object of ChatMember
		ChatMember(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
