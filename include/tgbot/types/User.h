#ifndef TYPES_USER_H
#define TYPES_USER_H

#include <string>
#include <memory>

namespace tgbot
{
	struct User
	{
		//pointer of itself
		typedef std::shared_ptr<User> ptr;

		//member variables
		long long id = -1;
		bool is_bot;
		std::string first_name;
		std::string last_name;
		std::string username;
		std::string language_code;

		//constructors
		User();

		//@param json: json object of User
		User(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
