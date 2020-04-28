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
		 * @var
		 */
		std::string id;
		/**
		 * @var
		 */
		std::string title;
		/**
		 * @var
		 */
		std::vector<LabeledPrice::ptr> prices;

		//Constructors
		ShippingOption();

		//@param json: json object of ShippingOption
		ShippingOption(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
