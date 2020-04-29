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
	 * @brief This object represents a chat.
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
		 * @var id
		 * @brief Unique identifier for this chat.
		 * @details This number may be greater than 32 bits and some programming languages may have difficulty/silent defects in interpreting it.
		 * @details But it is smaller than 52 bits, so a signed 64 bit integer or double-precision float type are safe for storing this identifier.
		 */
		long long id = -1;
		/**
		 * @var type
		 * @brief Type of chat, can be either “private”, “group”, “supergroup” or “channel”
		 */
		std::string type;
		/**
		 * @var title
		 * @brief Optional. Title, for supergroups, channels and group chats
		 */
		std::string title;
		/**
		 * @var username
		 * @brief Optional. Username, for private chats, supergroups and channels if available
		 */
		std::string username;
		/**
		 * @var first_name
		 * @brief Optional. First name of the other party in a private chat
		 */
		std::string first_name;
		/**
		 * @var last_name
		 * @brief Optional. Last name of the other party in a private chat
		 */
		std::string last_name;
		/**
		 * @var photo
		 * @brief Optional. Chat photo. Returned only in getChat.
		 */
		ChatPhoto::ptr photo;
		/**
		 * @var description
		 * @brief Optional. Description, for groups, supergroups and channel chats. Returned only in getChat.
		 */
		std::string description;
		/**
		 * @var invite_link
		 * @brief Optional. Chat invite link, for groups, supergroups and channel chats.
		 * @details Each administrator in a chat generates their own invite links, so the bot must first generate the link using exportChatInviteLink. Returned only in getChat.
		 */
		std::string invite_link;
		/**
		 * @var pinned_message
		 * @brief Optional. Pinned message, for groups, supergroups and channels. Returned only in getChat.
		 */
		std::shared_ptr<Message> pinned_message;
		/**
		 * @var permissions
		 * @brief Optional. Default chat member permissions, for groups and supergroups. Returned only in getChat.
		 */
		ChatPermissions::ptr permissions;
		/**
		 * @var slow_mode_delay
		 * @brief Optional. For supergroups, the minimum allowed delay between consecutive messages sent by each unpriviledged user. Returned only in getChat.
		 */
		int slow_mode_delay = -1;
		/**
		 * @var sticker_set_name
		 * @brief Optional. For supergroups, name of group sticker set. Returned only in getChat.
		 */
		std::string sticker_set_name;
		/**
		 * @var can_set_sticker_set
		 * @brief Optional. True, if the bot can change the group sticker set. Returned only in getChat.
		 */
		bool can_set_sticker_set;

		//Constructors
		Chat();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		Chat(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
