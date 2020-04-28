#ifndef TGBOT_TYPES_PRECHECKOUTQUERY_H
#define TGBOT_TYPES_PRECHECKOUTQUERY_H

#include <string>
#include "tgbot/types/User.h"
#include "tgbot/types/OrderInfo.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct PreCheckoutQuery
	 */
	struct PreCheckoutQuery
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PreCheckoutQuery> ptr;

		//Member variables
		std::string id;
		User::ptr from;
		std::string currency;
		int total_amount = -1;
		std::string invoice_payload;
		std::string shipping_option_id;
		OrderInfo::ptr order_info;

		//Constructors
		PreCheckoutQuery();

		//@param json: json object of PreCheckoutQuery
		PreCheckoutQuery(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
