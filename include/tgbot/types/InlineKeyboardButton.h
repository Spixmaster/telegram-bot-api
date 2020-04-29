#ifndef TGBOT_TYPES_INLINEKEYBOARDBUTTON_H
#define TGBOT_TYPES_INLINEKEYBOARDBUTTON_H

#include <string>
#include "tgbot/types/LoginUrl.h"
#include "tgbot/types/CallbackGame.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineKeyboardButton
	 * @brief This object represents one button of an inline keyboard. You must use exactly one of the optional fields.
	 */
	struct InlineKeyboardButton
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineKeyboardButton> ptr;

		//Member variables
		/**
		 * @var text
		 * @brief Label text on the button
		 */
		std::string text;
		/**
		 * @var url
		 * @brief Optional. HTTP or tg:// url to be opened when button is pressed
		 */
		std::string url;
		/**
		 * @var login_url
		 * @brief Optional. An HTTP URL used to automatically authorize the user. Can be used as a replacement for the Telegram Login Widget.
		 */
		LoginUrl::ptr login_url;
		/**
		 * @var callback_data
		 * @brief Optional. Data to be sent in a callback query to the bot when button is pressed, 1-64 bytes
		 */
		std::string callback_data;
		/**
		 * @var switch_inline_query
		 * @brief Optional. If set, pressing the button will prompt the user to select one of their chats, open that chat and insert the bot‘s username and the specified inline query in the input field.
		 * @details Can be empty, in which case just the bot’s username will be inserted.
		 * @note This offers an easy way for users to start using your bot in inline mode when they are currently in a private chat with it.
		 * @note Especially useful when combined with switch_pm… actions – in this case the user will be automatically returned to the chat they switched from, skipping the chat selection screen.
		 */
		std::string switch_inline_query;
		/**
		 * @var switch_inline_query_current_chat
		 * @brief Optional. If set, pressing the button will insert the bot‘s username and the specified inline query in the current chat’s input field. Can be empty, in which case only the bot's username will be inserted.
		 * @note This offers a quick way for the user to open your bot in inline mode in the same chat – good for selecting something from multiple options.
		 */
		std::string switch_inline_query_current_chat;
		/**
		 * @var callback_game
		 * @brief Optional. Description of the game that will be launched when the user presses the button.
		 * @note This type of button must always be the first button in the first row.
		 */
		CallbackGame::ptr callback_game;
		/**
		 * @var pay
		 * @brief Optional. Specify True, to send a Pay button.
		 * @note This type of button must always be the first button in the first row.
		 */
		bool pay;

		//Constructors
		InlineKeyboardButton();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineKeyboardButton(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
