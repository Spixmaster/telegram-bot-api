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
	 * @brief Contains information about the current status of a webhook.
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
		 * @var url
		 * @brief Webhook URL, may be empty if webhook is not set up
		 */
		std::string url;
		/**
		 * @var has_custom_certificate
		 * @brief True, if a custom certificate was provided for webhook certificate checks
		 */
		bool has_custom_certificate;
		/**
		 * @var pending_update_count
		 * @brief Number of updates awaiting delivery
		 */
		int pending_update_count;
		/**
		 * @var last_error_date
		 * @brief Optional. Unix time for the most recent error that happened when trying to deliver an update via webhook
		 */
		int last_error_date;
		/**
		 * @var last_error_message
		 * @brief Optional. Error message in human-readable format for the most recent error that happened when trying to deliver an update via webhook
		 */
		std::string last_error_message;
		/**
		 * @var max_connections
		 * @brief Optional. Maximum allowed number of simultaneous HTTPS connections to the webhook for update delivery
		 */
		int max_connections;
		/**
		 * @var allowed_updates
		 * @brief Optional. A list of update types the bot is subscribed to. Defaults to all update types
		 */
		std::vector<std::string> allowed_updates;

		//Constructors
		WebhookInfo();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		WebhookInfo(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
