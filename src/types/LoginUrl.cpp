#include <rapidjson/document.h>
#include "tgbot/types/LoginUrl.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

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
			//Assignments
			if(doc.HasMember("url"))
			{
				if(doc["url"].IsString())
					url = doc["url"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("url"));
			}

			if(doc.HasMember("forward_text"))
			{
				if(doc["forward_text"].IsString())
					forward_text = doc["forward_text"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("forward_text"));
			}

			if(doc.HasMember("bot_username"))
			{
				if(doc["bot_username"].IsString())
					bot_username = doc["bot_username"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("bot_username"));
			}

			if(doc.HasMember("request_write_access"))
			{
				if(doc["request_write_access"].IsBool())
					request_write_access = doc["request_write_access"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("request_write_access"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string LoginUrl::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field url
		json.append("\"url\": \"" + url + "\"");
		json.append(", ");

		//Field forward_text
		json.append("\"forward_text\": \"" + forward_text + "\"");
		json.append(", ");

		//Field bot_username
		json.append("\"bot_username\": \"" + bot_username + "\"");
		json.append(", ");

		//Field request_write_access
		std::string request_write_access_bool = request_write_access ? "true" : "false";
		json.append("\"request_write_access\": " + request_write_access_bool);

		json.append("}");
		return json;
	}
}
