#ifndef TGBOT_TYPES_SHIPPINGQUERY_H
#define TGBOT_TYPES_SHIPPINGQUERY_H

#include <string>
#include "tgbot/types/User.h"
#include "tgbot/types/ShippingAddress.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct ShippingQuery
	 * @brief This object contains information about an incoming shipping query.
	 */
	struct ShippingQuery
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<ShippingQuery> ptr;

		//Member variables
		/**
		 * @var id
		 * @brief Unique query identifier
		 */
		std::string id;
		/**
		 * @var from
		 * @brief User who sent the query
		 */
		User::ptr from;
		/**
		 * @var invoice_payload
		 * @brief Bot specified invoice payload
		 */
		std::string invoice_payload;
		/**
		 * @var shipping_address
		 * @brief User specified shipping address
		 */
		ShippingAddress::ptr shipping_address;

		//Constructors
		ShippingQuery();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		ShippingQuery(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
