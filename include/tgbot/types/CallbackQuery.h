#ifndef TGBOT_TYPES_CALLBACKQUERY_H
#define TGBOT_TYPES_CALLBACKQUERY_H

#include <string>
#include "tgbot/types/User.h"
#include "tgbot/types/Message.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct CallbackQuery
	 * @brief This object represents an incoming callback query from a callback button in an inline keyboard.
	 * @details If the button that originated the query was attached to a message sent by the bot, the field message will be present.
	 * @details If the button was attached to a message sent via the bot (in inline mode), the field inline_message_id will be present.
	 * @details Exactly one of the fields data or game_short_name will be present.
	 * @note After the user presses a callback button, Telegram clients will display a progress bar until you call answerCallbackQuery.
	 * @note It is, therefore, necessary to react by calling answerCallbackQuery even if no notification to the user is needed (e.g., without specifying any of the optional parameters).
	 */
	struct CallbackQuery
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<CallbackQuery> ptr;

		//Member variables
		/**
		 * @var id
		 * @brief Unique identifier for this query
		 */
		std::string id;
		/**
		 * @var from
		 * @brief Sender
		 */
		User::ptr from;
		/**
		 * @var message
		 * @brief Optional. Message with the callback button that originated the query. Note that message content and message date will not be available if the message is too old
		 */
		Message::ptr message;
		/**
		 * @var inline_message_id
		 * @brief Optional. Identifier of the message sent via the bot in inline mode, that originated the query.
		 */
		std::string inline_message_id;
		/**
		 * @var chat_instance
		 * @brief Global identifier, uniquely corresponding to the chat to which the message with the callback button was sent. Useful for high scores in games.
		 */
		std::string chat_instance;
		/**
		 * @var data
		 * @brief Optional. Data associated with the callback button. Be aware that a bad client can send arbitrary data in this field.
		 */
		std::string data;
		/**
		 * @var game_short_name
		 * @brief Optional. Short name of a Game to be returned, serves as the unique identifier for the game
		 */
		std::string game_short_name;

		//Constructors
		CallbackQuery();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		CallbackQuery(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
