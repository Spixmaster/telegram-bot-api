#ifndef TGBOT_TYPES_INLINEKEYBOARDMARKUP_H
#define TGBOT_TYPES_INLINEKEYBOARDMARKUP_H

#include "tgbot/types/InlineKeyboardButton.h"
#include <vector>
#include <memory>
#include "tgbot/types/Reply.h"

namespace tgbot
{
	/**
	 * @struct InlineKeyboardMarkup
	 * @brief This object represents an inline keyboard that appears right next to the message it belongs to.
	 * @note This will only work in Telegram versions released after 9 April, 2016. Older clients will display unsupported message.
	 */
	struct InlineKeyboardMarkup : public Reply
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineKeyboardMarkup> ptr;

		//Member variables
		/**
		 * @var inline_keyboard
		 * @brief Array of button rows, each represented by an Array of InlineKeyboardButton objects
		 */
		std::vector<std::vector<InlineKeyboardButton::ptr>> inline_keyboard;

		//Constructors
		InlineKeyboardMarkup();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineKeyboardMarkup(const std::string &json);

		/**
		 * @param[in] keyboard The vector of vectors of buttons represents a keyboard. One vector makes up a line.
		 */
		InlineKeyboardMarkup(const std::vector<std::vector<InlineKeyboardButton::ptr>> &keyboard);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
