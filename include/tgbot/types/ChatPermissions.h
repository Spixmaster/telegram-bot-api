#ifndef TGBOT_TYPES_CHATPERMISSIONS_H
#define TGBOT_TYPES_CHATPERMISSIONS_H

#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct ChatPermissions
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
		bool can_add_web_page_preview;
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

		//Constructors
		ChatPermissions();

		//@param json: json object of ChatPermissions
		ChatPermissions(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
