#ifndef TGBOT_TYPES_SHIPPINGQUERY_H
#define TGBOT_TYPES_SHIPPINGQUERY_H

#include <string>
#include "tgbot/types/User.h"
#include "tgbot/types/ShippingAddress.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct ShippingQuery
	 */
	struct ShippingQuery
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<ShippingQuery> ptr;

		//Member variables
		std::string id;
		User::ptr from;
		std::string invoice_payload;
		ShippingAddress::ptr shipping_address;

		//Constructors
		ShippingQuery();

		//@param json: json object of ShippingQuery
		ShippingQuery(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
