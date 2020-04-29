#ifndef TGBOT_TYPES_KEYBOARDBUTTON_H
#define TGBOT_TYPES_KEYBOARDBUTTON_H

#include <string>
#include <rapidjson/document.h>
#include <memory>
#include "tgbot/types/KeyboardButtonPollType.h"

namespace tgbot
{
	/**
	 * @struct KeyboardButton
	 * @brief This object represents one button of the reply keyboard.
	 * @details For simple text buttons String can be used instead of this object to specify text of the button.
	 * @details Optional fields request_contact, request_location, and request_poll are mutually exclusive.
	 * @note request_contact and request_location options will only work in Telegram versions released after 9 April, 2016. Older clients will display unsupported message.
	 * @note request_poll option will only work in Telegram versions released after 23 January, 2020. Older clients will display unsupported message.
	 */
	struct KeyboardButton
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<KeyboardButton> ptr;

		//Member variables
		/**
		 * @var text
		 * @brief Text of the button. If none of the optional fields are used, it will be sent as a message when the button is pressed
		 */
		std::string text;
		/**
		 * @var request_contact
		 * @brief Optional. If True, the user's phone number will be sent as a contact when the button is pressed. Available in private chats only
		 */
		bool request_contact = false;
		/**
		 * @var request_location
		 * @brief Optional. If True, the user's current location will be sent when the button is pressed. Available in private chats only
		 */
		bool request_location = false;
		/**
		 * @var request_poll
		 * @brief Optional. If specified, the user will be asked to create a poll and send it to the bot when the button is pressed. Available in private chats only
		 */
		KeyboardButtonPollType::ptr request_poll;

		//Constructors
		KeyboardButton();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		KeyboardButton(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
