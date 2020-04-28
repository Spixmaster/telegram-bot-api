#ifndef TGBOT_TYPES_LOGINURL_H
#define TGBOT_TYPES_LOGINURL_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct LoginUrl
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
		std::string url;
		std::string forward_text;
		std::string bot_username;
		bool request_write_access;

		//Constructors
		LoginUrl();

		//@param json: json object of LoginUrl
		LoginUrl(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
