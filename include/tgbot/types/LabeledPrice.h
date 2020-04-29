#ifndef TGBOT_TYPES_LABELEDPRICE_H
#define TGBOT_TYPES_LABELEDPRICE_H

#include <string>
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct LabeledPrice
	 * @brief This object represents a portion of the price for goods or services.
	 */
	struct LabeledPrice
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<LabeledPrice> ptr;

		//Member variables
		/**
		 * @var label
		 * @brief Portion label
		 */
		std::string label;
		/**
		 * @var amount
		 * @brief Price of the product in the smallest units of the currency (integer, not float/double).
		 * @details For example, for a price of US$ 1.45 pass amount = 145.
		 * @details See the exp parameter in currencies.json, it shows the number of digits past the decimal point for each currency (2 for the majority of currencies).
		 */
		int amount = -1;

		//Constructors
		LabeledPrice();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		LabeledPrice(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
