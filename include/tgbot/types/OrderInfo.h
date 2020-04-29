#ifndef TGBOT_TYPES_ORDERINFO_H
#define TGBOT_TYPES_ORDERINFO_H

#include <string>
#include "tgbot/types/ShippingAddress.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct OrderInfo
	 * @brief This object represents information about an order.
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
		/**
		 * @var name
		 * @brief Optional. User name
		 */
		std::string name;
		/**
		 * @var phone_number
		 * @brief Optional. User's phone number
		 */
		std::string phone_number;
		/**
		 * @var email
		 * @brief Optional. User email
		 */
		std::string email;
		/**
		 * @var shipping_address
		 * @brief Optional. User shipping address
		 */
		ShippingAddress::ptr shipping_address;

		//Constructors
		OrderInfo();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		OrderInfo(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
