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
	 * @details Example: A poll bot for groups runs in privacy mode (only receives commands, replies to its messages and mentions). There could be two ways to create a new poll:
	 * @details Explain the user how to send a command with parameters (e.g. /newpoll question answer1 answer2). May be appealing for hardcore users but lacks modern day polish.
	 * @details Guide the user through a step-by-step process. 'Please send me your question', 'Cool, now let's add the first answer option', 'Great. Keep adding answer options, then send /done when you're ready'.
	 * @details The last option is definitely more attractive. And if you use ForceReply in your bot's questions, it will receive the user's answers even if it only receives replies, commands and mentions — without any extra work for the user.
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
		bool force_reply;
		/**
		 * @var selective
		 * @brief Optional. Use this parameter if you want to force reply from specific users only. Targets: 1) users that are \@mentioned in the text of the Message object; 2) if the bot's message is a reply (has reply_to_message_id), sender of the original message.
		 */
		bool selective;

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
