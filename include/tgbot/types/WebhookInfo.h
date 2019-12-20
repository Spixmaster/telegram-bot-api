#ifndef TGBOT_TYPES_WEBHOOKINFO_H
#define TGBOT_TYPES_WEBHOOKINFO_H_

#include <string>
#include <vector>
#include <rapidjson/document.h>
#include "tgbot/SpecialTools.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct WebhookInfo
	{
		//pointer of itself
		typedef std::shared_ptr<WebhookInfo> ptr;

		//member variables
		std::string url;
		bool has_custom_certificate;
		int pending_update_count = -1;
		int last_error_date = -1;
		std::string last_error_message;
		int max_connections = -1;
		std::vector<std::string> allowed_updates;

		//constructors
		WebhookInfo();

		//@param json: json object of WebhookInfo
		WebhookInfo(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
