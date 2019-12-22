#ifndef TGBOT_TYPES_ORDERINFO_H
#define TGBOT_TYPES_ORDERINFO_H

#include <string>
#include "tgbot/types/ShippingAddress.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct OrderInfo
	{
		//pointer of itself
		typedef std::shared_ptr<OrderInfo> ptr;

		//member variables
		std::string name;
		std::string phone_number;
		std::string email;
		ShippingAddress::ptr shipping_address;

		//constructors
		OrderInfo();

		//@param json: json object of OrderInfo
		OrderInfo(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
