#ifndef TGBOT_TYPES_SHIPPINGOPTION_H
#define TGBOT_TYPES_SHIPPINGOPTION_H

#include <string>
#include <vector>
#include "tgbot/types/LabeledPrice.h"
#include "tgbot/SpecialTools.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct ShippingOption
	{
		//pointer of itself
		typedef std::shared_ptr<ShippingOption> ptr;

		//member variables
		std::string id;
		std::string title;
		std::vector<LabeledPrice::ptr> prices;

		//constructors
		ShippingOption();

		//@param json: json object of ShippingOption
		ShippingOption(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
