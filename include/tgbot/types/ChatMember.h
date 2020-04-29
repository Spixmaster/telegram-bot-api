#ifndef TGBOT_TYPES_CHATMEMBER_H
#define TGBOT_TYPES_CHATMEMBER_H

#include <string>
#include "tgbot/types/User.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct ChatMember
	 * @brief This object contains information about one member of a chat.
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
		 * @var user
		 * @brief Information about the user
		 */
		User::ptr user;
		/**
		 * @var status
		 * @brief The member's status in the chat. Can be “creator”, “administrator”, “member”, “restricted”, “left” or “kicked”
		 */
		std::string status;
		/**
		 * @var custom_title
		 * @brief Optional. Owner and administrators only. Custom title for this user
		 */
		std::string custom_title;
		/**
		 * @var until_date
		 * @brief Optional. Restricted and kicked only. Date when restrictions will be lifted for this user; unix time
		 */
		int until_date = -1;
		/**
		 * @var can_be_edited
		 * @brief Optional. Administrators only. True, if the bot is allowed to edit administrator privileges of that user
		 */
		bool can_be_edited;
		/**
		 * @var can_post_messages
		 * @brief Optional. Administrators only. True, if the administrator can post in the channel; channels only
		 */
		bool can_post_messages;
		/**
		 * @var can_edit_messages
		 * @brief Optional. Administrators only. True, if the administrator can edit messages of other users and can pin messages; channels only
		 */
		bool can_edit_messages;
		/**
		 * @var can_delete_messages
		 * @brief Optional. Administrators only. True, if the administrator can delete messages of other users
		 */
		bool can_delete_messages;
		/**
		 * @var can_restrict_members
		 * @brief Optional. Administrators only. True, if the administrator can restrict, ban or unban chat members
		 */
		bool can_restrict_members;
		/**
		 * @var can_promote_members
		 * @brief Optional. Administrators only. True, if the administrator can add new administrators with a subset of their own privileges or demote administrators that he has promoted, directly or indirectly (promoted by administrators that were appointed by the user)
		 */
		bool can_promote_members;
		/**
		 * @var can_change_info
		 * @brief Optional. Administrators and restricted only. True, if the user is allowed to change the chat title, photo and other settings
		 */
		bool can_change_info;
		/**
		 * @var can_invite_users
		 * @brief Optional. Administrators and restricted only. True, if the user is allowed to invite new users to the chat
		 */
		bool can_invite_users;
		/**
		 * @var can_pin_messages
		 * @brief Optional. Administrators and restricted only. True, if the user is allowed to pin messages; groups and supergroups only
		 */
		bool can_pin_messages;
		/**
		 * @var is_member
		 * @brief Optional. Restricted only. True, if the user is a member of the chat at the moment of the request
		 */
		bool is_member;
		/**
		 * @var can_send_messages
		 * @brief Optional. Restricted only. True, if the user is allowed to send text messages, contacts, locations and venues
		 */
		bool can_send_messages;
		/**
		 * @var can_send_media_messages
		 * @brief Optional. Restricted only. True, if the user is allowed to send audios, documents, photos, videos, video notes and voice notes
		 */
		bool can_send_media_messages;
		/**
		 * @var can_send_polls
		 * @brief Optional. Restricted only. True, if the user is allowed to send polls
		 */
		bool can_send_polls;
		/**
		 * @var can_send_other_messages
		 * @brief Optional. Restricted only. True, if the user is allowed to send animations, games, stickers and use inline bots
		 */
		bool can_send_other_messages;
		/**
		 * @var can_add_web_page_previews
		 * @brief Optional. Restricted only. True, if the user is allowed to add web page previews to their messages
		 */
		bool can_add_web_page_previews;

		//Constructors
		ChatMember();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		ChatMember(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
