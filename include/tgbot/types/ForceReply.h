#ifndef TGBOT_TYPES_FORCEREPLY_H
#define TGBOT_TYPES_FORCEREPLY_H

#include <rapidjson/document.h>
#include <memory>
#include "tgbot/types/Reply.h"

namespace tgbot
{
	/**
	 * @struct ForceReply
	 * @brief Upon receiving a message with this object, Telegram clients will display a reply interface to the user (act as if the user has selected the bot‘s message and tapped ’Reply').
	 * @details This can be extremely useful if you want to create user-friendly step-by-step interfaces without having to sacrifice privacy mode.
	 */
	struct ForceReply : public Reply
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<ForceReply> ptr;

		//Member variables
		/**
		 * @var force_reply
		 * @brief Shows reply interface to the user, as if they manually selected the bot‘s message and tapped ’Reply'
		 */
		bool force_reply = true;
		/**
		 * @var selective
		 * @brief Optional. Use this parameter if you want to force reply from specific users only. Targets: 1) users that are @mentioned in the text of the Message object; 2) if the bot's message is a reply (has reply_to_message_id), sender of the original message.
		 */
		bool selective = false;

		//Constructors
		ForceReply();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		ForceReply(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
