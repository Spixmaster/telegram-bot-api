#ifndef TGBOT_TYPES_SHIPPINGADDRESS_H
#define TGBOT_TYPES_SHIPPINGADDRESS_H

#include <string>
#include <rapidjson/document.h>
#include <memory>


namespace tgbot
{
	/**
	 * @struct ShippingAddress
	 * @brief This object represents a shipping address.
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
		 * @var country_code
		 * @brief ISO 3166-1 alpha-2 country code
		 */
		std::string country_code;
		/**
		 * @var state
		 * @brief State, if applicable
		 */
		std::string state;
		/**
		 * @var city
		 * @brief City
		 */
		std::string city;
		/**
		 * @var street_line1
		 * @brief First line for the address
		 */
		std::string street_line1;
		/**
		 * @var street_line2
		 * @brief Second line for the address
		 */
		std::string street_line2;
		/**
		 * @var post_code
		 * @brief Address post code
		 */
		std::string post_code;

		//Constructors
		ShippingAddress();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		ShippingAddress(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
