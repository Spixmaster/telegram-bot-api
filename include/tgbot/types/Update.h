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
		 * @var
		 */
		int update_id = -1;
		/**
		 * @var
		 */
		Message::ptr message;
		/**
		 * @var
		 */
		Message::ptr edited_message;
		/**
		 * @var
		 */
		Message::ptr channel_post;
		/**
		 * @var
		 */
		Message::ptr edited_channel_post;
		/**
		 * @var
		 */
		InlineQuery::ptr inline_query;
		/**
		 * @var
		 */
		ChosenInlineResult::ptr chosen_inline_result;
		/**
		 * @var
		 */
		CallbackQuery::ptr callback_query;
		/**
		 * @var
		 */
		ShippingQuery::ptr shipping_query;
		/**
		 * @var
		 */
		PreCheckoutQuery::ptr pre_checkout_query;
		/**
		 * @var
		 */
		Poll::ptr poll;
		/**
		 * @var
		 */
		PollAnswer::ptr poll_answer;

		//Constructors
		Update();

		//@param json: json object of Update
		Update(std::string json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
