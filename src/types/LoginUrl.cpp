#include <rapidjson/document.h>
#include "tgbot/types/LoginUrl.h"

namespace tgbot
{
	LoginUrl::LoginUrl() : url(), forward_text(), bot_username(), request_write_access()
	{}

	LoginUrl::LoginUrl(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("url"))
			url = doc["url"].GetString();

		if(doc.HasMember("forward_text"))
			forward_text = doc["forward_text"].GetString();

		if(doc.HasMember("bot_username"))
			bot_username = doc["bot_username"].GetString();

		if(doc.HasMember("request_write_access"))
			request_write_access = doc["request_write_access"].GetBool();
	}

	std::string LoginUrl::parse_to_json() const
	{
		std::string json = "{";

		//field url
		json.append("\"url\": \"" + url + "\"");
		json.append(", ");

		//field forward_text
		json.append("\"forward_text\": \"" + forward_text + "\"");
		json.append(", ");

		//field bot_username
		json.append("\"bot_username\": \"" + bot_username + "\"");
		json.append(", ");

		//field request_write_access
		std::string request_write_access_bool = request_write_access ? "true" : "false";
		json.append("\"request_write_access\": " + request_write_access_bool);

		json.append("}");

		return json;
	}
}
