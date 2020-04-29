#ifndef TGBOT_TYPES_UPDATE_H
#define TGBOT_TYPES_UPDATE_H

#include <string>
#include "tgbot/types/Message.h"
#include "tgbot/types/InlineQuery.h"
#include "tgbot/types/ChosenInlineResult.h"
#include "tgbot/types/CallbackQuery.h"
#include "tgbot/types/ShippingQuery.h"
#include "tgbot/types/PreCheckoutQuery.h"
#include "tgbot/types/Poll.h"
#include <rapidjson/document.h>
#include <memory>
#include "tgbot/types/PollAnswer.h"

namespace tgbot
{
	/**
	 * @struct Update
	 * @brief This object represents an incoming update.
	 * @details At most one of the optional parameters can be present in any given update.
	 */
	struct Update
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Update> ptr;

		//Member variables
		/**
		 * @var update_id
		 * @brief The update‘s unique identifier.
		 * @details Update identifiers start from a certain positive number and increase sequentially.
		 * @details This ID becomes especially handy if you’re using Webhooks, since it allows you to ignore repeated updates or to restore the correct update sequence, should they get out of order.
		 * @detils If there are no new updates for at least a week, then identifier of the next update will be chosen randomly instead of sequentially.
		 */
		int update_id = -1;
		/**
		 * @var message
		 * @brief Optional. New incoming message of any kind — text, photo, sticker, etc.
		 */
		Message::ptr message;
		/**
		 * @var edited_message
		 * @brief Optional. New version of a message that is known to the bot and was edited
		 */
		Message::ptr edited_message;
		/**
		 * @var channel_post
		 * @brief Optional. New incoming channel post of any kind — text, photo, sticker, etc.
		 */
		Message::ptr channel_post;
		/**
		 * @var edited_channel_post
		 * @brief Optional. New version of a channel post that is known to the bot and was edited
		 */
		Message::ptr edited_channel_post;
		/**
		 * @var inline_query
		 * @brief Optional. New incoming inline query
		 */
		InlineQuery::ptr inline_query;
		/**
		 * @var chosen_inline_result
		 * @brief Optional. The result of an inline query that was chosen by a user and sent to their chat partner.
		 * @details Please see our documentation on the feedback collecting for details on how to enable these updates for your bot.
		 */
		ChosenInlineResult::ptr chosen_inline_result;
		/**
		 * @var callback_query
		 * @brief Optional. New incoming callback query
		 */
		CallbackQuery::ptr callback_query;
		/**
		 * @var shipping_query
		 * @brief Optional. New incoming shipping query. Only for invoices with flexible price
		 */
		ShippingQuery::ptr shipping_query;
		/**
		 * @var pre_checkout_query
		 * @brief Optional. New incoming pre-checkout query. Contains full information about checkout
		 */
		PreCheckoutQuery::ptr pre_checkout_query;
		/**
		 * @var poll
		 * @brief Optional. New poll state. Bots receive only updates about stopped polls and polls, which are sent by the bot
		 */
		Poll::ptr poll;
		/**
		 * @var poll_answer
		 * @brief Optional. A user changed their answer in a non-anonymous poll. Bots receive new votes only in polls that were sent by the bot itself.
		 */
		PollAnswer::ptr poll_answer;

		//Constructors
		Update();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		Update(std::string json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
