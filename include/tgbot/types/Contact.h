#ifndef TGBOT_TYPES_CONTACT_H
#define TGBOT_TYPES_CONTACT_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct Contact
	 * @brief This object represents a phone contact.
	 */
	struct Contact
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Contact> ptr;

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
		 * @var user_id
		 * @brief Optional. Contact's user identifier in Telegram
		 */
		int user_id = -1;
		/**
		 * @var vcard
		 * @brief Optional. Additional data about the contact in the form of a vCard
		 */
		std::string vcard;

		//Constructors
		Contact();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		Contact(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
