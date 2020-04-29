#ifndef TGBOT_TYPES_INPUTCONTACTMESSAGECONTENT_H
#define TGBOT_TYPES_INPUTCONTACTMESSAGECONTENT_H

#include <string>
#include "tgbot/types/InputMessageContent.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InputContactMessageContent
	 * @brief Represents the content of a contact message to be sent as the result of an inline query.
	 */
	struct InputContactMessageContent : public InputMessageContent
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InputContactMessageContent> ptr;

		//Member variables
		/**
		 * @var phone_number
		 * @brief Contact's phone number
		 */
		std::string phone_number;
		/**
		 * @var first_name
		 * @brief Contact's first name
		 */
		std::string first_name;
		/**
		 * @var last_name
		 * @brief Optional. Contact's last name
		 */
		std::string last_name;
		/**
		 * @var vcard
		 * @brief Optional. Additional data about the contact in the form of a vCard, 0-2048 bytes
		 */
		std::string vcard;

		//Constructors
		InputContactMessageContent();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InputContactMessageContent(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
