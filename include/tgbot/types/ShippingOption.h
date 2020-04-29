#ifndef TGBOT_TYPES_SHIPPINGOPTION_H
#define TGBOT_TYPES_SHIPPINGOPTION_H

#include <string>
#include <vector>
#include "tgbot/types/LabeledPrice.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct ShippingOption
	 * @brief This object represents one shipping option.
	 */
	struct ShippingOption
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<ShippingOption> ptr;

		//Member variables
		/**
		 * @var id
		 * @brief Shipping option identifier
		 */
		std::string id;
		/**
		 * @var title
		 * @brief Option title
		 */
		std::string title;
		/**
		 * @var prices
		 * @brief List of price portions
		 */
		std::vector<LabeledPrice::ptr> prices;

		//Constructors
		ShippingOption();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		ShippingOption(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
