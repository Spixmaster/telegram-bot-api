#ifndef TGBOT_TYPES_ORDERINFO_H
#define TGBOT_TYPES_ORDERINFO_H

#include <string>
#include "tgbot/types/ShippingAddress.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct OrderInfo
	 */
	struct OrderInfo
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<OrderInfo> ptr;

		//Member variables
		std::string name;
		std::string phone_number;
		std::string email;
		ShippingAddress::ptr shipping_address;

		//Constructors
		OrderInfo();

		//@param json: json object of OrderInfo
		OrderInfo(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
