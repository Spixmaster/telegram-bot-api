#ifndef TGBOT_TYPES_SUCCESSFULPAYMENT_H
#define TGBOT_TYPES_SUCCESSFULPAYMENT_H

#include <string>
#include "tgbot/types/OrderInfo.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct SuccessfulPayment
	 * @brief This object contains basic information about a successful payment.
	 */
	struct SuccessfulPayment
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<SuccessfulPayment> ptr;

		//Member variables
		/**
		 * @var currency
		 * @brief Three-letter ISO 4217 currency code
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
		/**
		 * @var telegram_payment_charge_id
		 * @brief Telegram payment identifier
		 */
		std::string telegram_payment_charge_id;
		/**
		 * @var provider_payment_charge_id
		 * @brief Provider payment identifier
		 */
		std::string provider_payment_charge_id;

		//Constructors
		SuccessfulPayment();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		SuccessfulPayment(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
