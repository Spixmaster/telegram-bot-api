#ifndef TGBOT_TYPES_CHATPERMISSIONS_H
#define TGBOT_TYPES_CHATPERMISSIONS_H

#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct ChatPermissions
	 * @brief Describes actions that a non-administrator user is allowed to take in a chat.
	 */
	struct ChatPermissions
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<ChatPermissions> ptr;

		//Member variables
		/**
		 * @var can_send_messages
		 * @brief Optional. True, if the user is allowed to send text messages, contacts, locations and venues
		 */
		bool can_send_messages;
		/**
		 * @var can_send_media_messages
		 * @brief Optional. True, if the user is allowed to send audios, documents, photos, videos, video notes and voice notes, implies can_send_messages
		 */
		bool can_send_media_messages;
		/**
		 * @var can_send_polls
		 * @brief Optional. True, if the user is allowed to send polls, implies can_send_messages
		 */
		bool can_send_polls;
		/**
		 * @var can_send_other_messages
		 * @brief Optional. True, if the user is allowed to send animations, games, stickers and use inline bots, implies can_send_media_messages
		 */
		bool can_send_other_messages;
		/**
		 * @var can_add_web_page_preview
		 * @brief Optional. True, if the user is allowed to add web page previews to their messages, implies can_send_media_messages
		 */
		bool can_add_web_page_preview;
		/**
		 * @var can_change_info
		 * @brief Optional. True, if the user is allowed to change the chat title, photo and other settings. Ignored in public supergroups
		 */
		bool can_change_info;
		/**
		 * @var can_invite_users
		 * @brief Optional. True, if the user is allowed to invite new users to the chat
		 */
		bool can_invite_users;
		/**
		 * @var can_pin_messages
		 * @brief Optional. True, if the user is allowed to pin messages. Ignored in public supergroups
		 */
		bool can_pin_messages;

		//Constructors
		ChatPermissions();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		ChatPermissions(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
