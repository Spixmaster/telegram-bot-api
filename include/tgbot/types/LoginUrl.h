#ifndef TGBOT_TYPES_LOGINURL_H
#define TGBOT_TYPES_LOGINURL_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct LoginUrl
	 * @brief This object represents a parameter of the inline keyboard button used to automatically authorize a user.
	 * @details Serves as a great replacement for the Telegram Login Widget when the user is coming from Telegram.
	 * @details All the user needs to do is tap/click a button and confirm that they want to log in:
	 * @details Telegram apps support these buttons as of version 5.7.
	 * @details Sample bot: \@discussbot
	 */
	struct LoginUrl
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<LoginUrl> ptr;

		//Member variables
		/**
		 * @var url
		 * @brief An HTTP URL to be opened with user authorization data added to the query string when the button is pressed.
		 * @details If the user refuses to provide authorization data, the original URL without information about the user will be opened.
		 * @details The data added is the same as described in Receiving authorization data.
		 * @note You must always check the hash of the received data to verify the authentication and the integrity of the data as described in Checking authorization.
		 */
		std::string url;
		/**
		 * @var forward_text
		 * @brief Optional. New text of the button in forwarded messages.
		 */
		std::string forward_text;
		/**
		 * @var bot_username
		 * @brief Optional. Username of a bot, which will be used for user authorization. See Setting up a bot for more details. If not specified, the current bot's username will be assumed. The url's domain must be the same as the domain linked with the bot. See Linking your domain to the bot for more details.
		 */
		std::string bot_username;
		/**
		 * @var request_write_access
		 * @brief Optional. Pass True to request the permission for your bot to send messages to the user.
		 */
		bool request_write_access;

		//Constructors
		LoginUrl();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		LoginUrl(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
