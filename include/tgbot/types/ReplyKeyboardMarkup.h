#ifndef TGBOT_TYPES_REPLYKEYBOARDMARKUP_H
#define TGBOT_TYPES_REPLYKEYBOARDMARKUP_H

#include "tgbot/types/KeyboardButton.h"
#include <vector>
#include <memory>
#include "tgbot/types/Reply.h"

namespace tgbot
{
	/**
	 * @struct ReplyKeyboardMarkup
	 * @brief This object represents a custom keyboard with reply options (see Introduction to bots for details and examples).
	 */
	struct ReplyKeyboardMarkup : public Reply
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<ReplyKeyboardMarkup> ptr;

		//Member variables
		/**
		 * @var keyboard
		 * @brief Array of button rows, each represented by an Array of KeyboardButton objects
		 */
		std::vector<std::vector<KeyboardButton::ptr>> keyboard;
		/**
		 * @var resize_keyboard
		 * @brief Optional. Requests clients to resize the keyboard vertically for optimal fit (e.g., make the keyboard smaller if there are just two rows of buttons).
		 * @details Defaults to false, in which case the custom keyboard is always of the same height as the app's standard keyboard.
		 */
		bool resize_keyboard;
		/**
		 * @var one_time_keyboard
		 * @brief Optional. Requests clients to hide the keyboard as soon as it's been used.
		 * @details The keyboard will still be available, but clients will automatically display the usual letter-keyboard in the chat – the user can press a special button in the input field to see the custom keyboard again.
		 * @details Defaults to false.
		 */
		bool one_time_keyboard;
		/**
		 * @var selective
		 * @brief Optional. Use this parameter if you want to show the keyboard to specific users only.
		 * @details Targets: 1) users that are \@mentioned in the text of the Message object; 2) if the bot's message is a reply (has reply_to_message_id), sender of the original message.
		 * @details Example: A user requests to change the bot‘s language, bot replies to the request with a keyboard to select the new language. Other users in the group don’t see the keyboard.
		 */
		bool selective;

		//Constructors
		ReplyKeyboardMarkup();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		ReplyKeyboardMarkup(const std::string &json);

		/**
		 * @param[in] keyboard The vector of vectors of buttons represents a keyboard. One vector makes up a line.
		 */
		ReplyKeyboardMarkup(const std::vector<std::vector<KeyboardButton::ptr>> &keyboard);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
