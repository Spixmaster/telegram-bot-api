#ifndef TGBOT_TYPES_PRECHECKOUTQUERY_H
#define TGBOT_TYPES_PRECHECKOUTQUERY_H

#include <string>
#include "tgbot/types/User.h"
#include "tgbot/types/OrderInfo.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct PreCheckoutQuery
	{
		//pointer of itself
		typedef std::shared_ptr<PreCheckoutQuery> ptr;

		//member variables
		std::string id;
		User::ptr from;
		std::string currency;
		int total_amount = -1;
		std::string invoice_payload;
		std::string shipping_option_id;
		OrderInfo::ptr order_info;

		//constructors
		PreCheckoutQuery();

		//@param json: json object of PreCheckoutQuery
		PreCheckoutQuery(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
