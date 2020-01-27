#include <rapidjson/document.h>
#include "tgbot/types/LoginUrl.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	LoginUrl::LoginUrl() : url(), forward_text(), bot_username(), request_write_access()
	{}

	LoginUrl::LoginUrl(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("url"))
			{
				if(doc["url"].IsString())
					url = doc["url"].GetString();
				else
					std::cerr << "Error: Field \"url\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("forward_text"))
			{
				if(doc["forward_text"].IsString())
					forward_text = doc["forward_text"].GetString();
				else
					std::cerr << "Error: Field \"forward_text\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("bot_username"))
			{
				if(doc["bot_username"].IsString())
					bot_username = doc["bot_username"].GetString();
				else
					std::cerr << "Error: Field \"bot_username\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("request_write_access"))
			{
				if(doc["request_write_access"].IsBool())
					request_write_access = doc["request_write_access"].GetBool();
				else
					std::cerr << "Error: Field \"request_write_access\" does not contain a bool." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
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
