#ifndef TGBOT_TYPES_USER_H
#define TGBOT_TYPES_USER_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct User
	 */
	struct User
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<User> ptr;

		//Member variables
		/**
		 * @var
		 */
		long long id = -1;
		/**
		 * @var
		 */
		bool is_bot;
		/**
		 * @var
		 */
		std::string first_name;
		/**
		 * @var
		 */
		std::string last_name;
		/**
		 * @var
		 */
		std::string username;
		/**
		 * @var
		 */
		std::string language_code;
		/**
		 * @var
		 */
		bool can_join_groups;
		/**
		 * @var
		 */
		bool can_read_all_group_messages;
		/**
		 * @var
		 */
		bool supports_inline_queries;

		//Constructors
		User();

		//@param json: json object of User
		User(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
