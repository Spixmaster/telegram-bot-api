#ifndef TGBOT_TYPES_INVOICE_H
#define TGBOT_TYPES_INVOICE_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct Invoice
	 * @brief This object contains basic information about an invoice.
	 */
	struct Invoice
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Invoice> ptr;

		//Member variables
		/**
		 * @var title
		 * @brief Product name
		 */
		std::string title;
		/**
		 * @var description
		 * @brief Product description
		 */
		std::string description;
		/**
		 * @var start_parameter
		 * @brief Unique bot deep-linking parameter that can be used to generate this invoice
		 */
		std::string start_parameter;
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
		int total_amount;

		//Constructors
		Invoice();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		Invoice(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
