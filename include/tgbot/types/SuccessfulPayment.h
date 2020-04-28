#ifndef TGBOT_TYPES_SUCCESSFULPAYMENT_H
#define TGBOT_TYPES_SUCCESSFULPAYMENT_H

#include <string>
#include "tgbot/types/OrderInfo.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct SuccessfulPayment
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
		std::string currency;
		int total_amount = -1;
		std::string invoice_payload;
		std::string shipping_option_id;
		OrderInfo::ptr order_info;
		std::string telegram_payment_charge_id;
		std::string provider_payment_charge_id;

		//Constructors
		SuccessfulPayment();

		//@param json: json object of SuccessfulPayment
		SuccessfulPayment(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
