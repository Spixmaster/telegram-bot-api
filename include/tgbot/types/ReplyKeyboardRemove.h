#ifndef TGBOT_TYPES_REPLYKEYBOARDREMOVE_H
#define TGBOT_TYPES_REPLYKEYBOARDREMOVE_H

#include <rapidjson/document.h>
#include <memory>
#include "tgbot/types/Reply.h"

namespace tgbot
{
	/**
	 * @struct ReplyKeyboardRemove
	 * @brief Upon receiving a message with this object, Telegram clients will remove the current custom keyboard and display the default letter-keyboard.
	 * @details By default, custom keyboards are displayed until a new keyboard is sent by a bot. An exception is made for one-time keyboards that are hidden immediately after the user presses a button (see ReplyKeyboardMarkup).
	 */
	struct ReplyKeyboardRemove : public Reply
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<ReplyKeyboardRemove> ptr;

		//Member variables
		/**
		 * @var remove_keyboard
		 * @brief Requests clients to remove the custom keyboard (user will not be able to summon this keyboard; if you want to hide the keyboard from sight but keep it accessible, use one_time_keyboard in ReplyKeyboardMarkup)
		 */
		bool remove_keyboard;
		/**
		 * @var selective
		 * @brief Optional. Use this parameter if you want to remove the keyboard for specific users only.
		 * @details Targets: 1) users that are \@mentioned in the text of the Message object; 2) if the bot's message is a reply (has reply_to_message_id), sender of the original message.
		 * @details Example: A user votes in a poll, bot returns confirmation message in reply to the vote and removes the keyboard for that user, while still showing the keyboard with poll options to users who haven't voted yet.
		 */
		bool selective;

		//Constructors
		ReplyKeyboardRemove();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		ReplyKeyboardRemove(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
