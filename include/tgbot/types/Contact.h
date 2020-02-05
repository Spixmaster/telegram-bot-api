#ifndef TGBOT_TYPES_CONTACT_H
#define TGBOT_TYPES_CONTACT_H

#include <string>
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct Contact
	{
		//pointer of itself
		typedef std::shared_ptr<Contact> ptr;

		//member variables
		std::string phone_number;
		std::string first_name;
		std::string last_name;
		int user_id = -1;
		std::string vcard;

		//constructors
		Contact();

		//@param json: json object of Contact
		Contact(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
