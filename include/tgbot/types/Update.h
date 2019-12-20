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

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct Update
	{
		//pointer of itself
		typedef std::shared_ptr<Update> ptr;

		//member variables
		int update_id = -1;
		Message::ptr message;
		Message::ptr edited_message;
		Message::ptr channel_post;
		Message::ptr edited_channel_post;
		InlineQuery::ptr inline_query;
		ChosenInlineResult::ptr chosen_inline_result;
		CallbackQuery::ptr callback_query;
		ShippingQuery::ptr shipping_query;
		PreCheckoutQuery::ptr pre_checkout_query;
		Poll::ptr poll;

		//constructors
		Update();

		//@param json: json object of Update
		Update(std::string json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
