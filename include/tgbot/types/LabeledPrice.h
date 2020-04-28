#ifndef TGBOT_TYPES_LABELEDPRICE_H
#define TGBOT_TYPES_LABELEDPRICE_H

#include <string>
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct LabeledPrice
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
		std::string label;
		int amount = -1;

		//Constructors
		LabeledPrice();

		//@param json: json object of LabeledPrice
		LabeledPrice(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
