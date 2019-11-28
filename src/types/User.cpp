#include "tgbot/types/User.h"
#include <rapidjson/document.h>
#include "tgbot/Tools.h"

namespace tgbot
{
	User::User() : id(), is_bot(), first_name(), last_name(), username(), language_code()
	{}

	User::User(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("id"))
				id = doc["id"].GetInt();

			if(doc.HasMember("is_bot"))
				is_bot = doc["is_bot"].GetBool();

			if(doc.HasMember("first_name"))
				first_name = doc["first_name"].GetString();

			if(doc.HasMember("last_name"))
				last_name = doc["last_name"].GetString();

			if(doc.HasMember("username"))
				username = doc["username"].GetString();

			if(doc.HasMember("language_code"))
				language_code = doc["language_code"].GetString();
		}
	}

	std::string User::parse_to_json() const
	{
		std::string json = "{";

		//field id
		json.append("\"id\": " + id);
		json.append(", ");

		//field is_bot
		std::string is_bot_bool = is_bot ? "true" : "false";
		json.append("\"is_bot\": \"" + is_bot_bool + "\"");
		json.append(", ");

		//field first_name
		json.append("\"first_name\": \"" + first_name + "\"");
		json.append(", ");

		//field last_name
		json.append("\"last_name\": \"" + last_name + "\"");
		json.append(", ");

		//field username
		json.append("\"username\": \"" + username + "\"");
		json.append(", ");

		//field language_code
		json.append("\"language_code\": \"" + language_code + "\"");

		json.append("}");

		return json;
	}
}
