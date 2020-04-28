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
		/**
		 * @var
		 */
		std::string currency;
		/**
		 * @var
		 */
		int total_amount = -1;
		/**
		 * @var
		 */
		std::string invoice_payload;
		/**
		 * @var
		 */
		std::string shipping_option_id;
		/**
		 * @var
		 */
		OrderInfo::ptr order_info;
		/**
		 * @var
		 */
		std::string telegram_payment_charge_id;
		/**
		 * @var
		 */
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
