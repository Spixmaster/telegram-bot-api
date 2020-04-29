#ifndef TGBOT_TYPES_USER_H
#define TGBOT_TYPES_USER_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct User
	 * @brief This object represents a Telegram user or bot.
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
		 * @var id
		 * @brief Unique identifier for this user or bot
		 */
		long long id = -1;
		/**
		 * @var is_bot
		 * @brief True, if this user is a bot
		 */
		bool is_bot;
		/**
		 * @var first_name
		 * @brief User‘s or bot’s first name
		 */
		std::string first_name;
		/**
		 * @var last_name
		 * @brief Optional. User‘s or bot’s last name
		 */
		std::string last_name;
		/**
		 * @var username
		 * @brief Optional. User‘s or bot’s username
		 */
		std::string username;
		/**
		 * @var language_code
		 * @brief Optional. IETF language tag of the user's language
		 */
		std::string language_code;
		/**
		 * @var can_join_groups
		 * @brief Optional. True, if the bot can be invited to groups. Returned only in getMe.
		 */
		bool can_join_groups;
		/**
		 * @var can_read_all_group_messages
		 * @brief Optional. True, if privacy mode is disabled for the bot. Returned only in getMe.
		 */
		bool can_read_all_group_messages;
		/**
		 * @var supports_inline_queries
		 * @brief Optional. True, if the bot supports inline queries. Returned only in getMe.
		 */
		bool supports_inline_queries;

		//Constructors
		User();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		User(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
