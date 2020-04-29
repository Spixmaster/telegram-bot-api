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
	 * @brief This object contains information about an incoming pre-checkout query.
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
		/**
		 * @var id
		 * @brief Unique query identifier
		 */
		std::string id;
		/**
		 * @var from
		 * @brief  	User who sent the query
		 */
		User::ptr from;
		/**
		 * @var currency
		 * @brief  	Three-letter ISO 4217 currency code
		 */
		std::string currency;
		/**
		 * @var total_amount
		 * @brief Total price in the smallest units of the currency (integer, not float/double).
		 * @details For example, for a price of US$ 1.45 pass amount = 145.
		 * @details See the exp parameter in currencies.json, it shows the number of digits past the decimal point for each currency (2 for the majority of currencies).
		 */
		int total_amount = -1;
		/**
		 * @var invoice_payload
		 * @brief Bot specified invoice payload
		 */
		std::string invoice_payload;
		/**
		 * @var shipping_option_id
		 * @brief Optional. Identifier of the shipping option chosen by the user
		 */
		std::string shipping_option_id;
		/**
		 * @var order_info
		 * @brief Optional. Order info provided by the user
		 */
		OrderInfo::ptr order_info;

		//Constructors
		PreCheckoutQuery();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		PreCheckoutQuery(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
