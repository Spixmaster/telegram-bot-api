#ifndef TGBOT_TYPES_CONTACT_H
#define TGBOT_TYPES_CONTACT_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct Contact
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
		std::string phone_number;
		std::string first_name;
		std::string last_name;
		int user_id = -1;
		std::string vcard;

		//Constructors
		Contact();

		//@param json: json object of Contact
		Contact(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
