#ifndef TGBOT_TYPES_WEBHOOKINFO_H
#define TGBOT_TYPES_WEBHOOKINFO_H_

#include <string>
#include <vector>
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct WebhookInfo
	 */
	struct WebhookInfo
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<WebhookInfo> ptr;

		//Member variables
		/**
		 * @var
		 */
		std::string url;
		/**
		 * @var
		 */
		bool has_custom_certificate;
		/**
		 * @var
		 */
		int pending_update_count = -1;
		/**
		 * @var
		 */
		int last_error_date = -1;
		/**
		 * @var
		 */
		std::string last_error_message;
		/**
		 * @var
		 */
		int max_connections = -1;
		/**
		 * @var
		 */
		std::vector<std::string> allowed_updates;

		//Constructors
		WebhookInfo();

		//@param json: json object of WebhookInfo
		WebhookInfo(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
