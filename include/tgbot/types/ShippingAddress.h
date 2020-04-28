#ifndef TGBOT_TYPES_SHIPPINGADDRESS_H
#define TGBOT_TYPES_SHIPPINGADDRESS_H

#include <string>
#include <rapidjson/document.h>
#include <memory>


namespace tgbot
{
	/**
	 * @struct ShippingAddress
	 */
	struct ShippingAddress
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<ShippingAddress> ptr;

		//Member variables
		/**
		 * @var
		 */
		std::string country_code;
		/**
		 * @var
		 */
		std::string state;
		/**
		 * @var
		 */
		std::string city;
		/**
		 * @var
		 */
		std::string street_line1;
		/**
		 * @var
		 */
		std::string street_line2;
		/**
		 * @var
		 */
		std::string post_code;

		//Constructors
		ShippingAddress();

		//@param json: json object of ShippingAddress
		ShippingAddress(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
