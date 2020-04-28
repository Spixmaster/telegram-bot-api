#include "tgbot/types/User.h"
#include <rapidjson/document.h>
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	User::User() : id(), is_bot(), first_name(), last_name(), username(), language_code(), can_join_groups(), can_read_all_group_messages(), supports_inline_queries()
	{}

	User::User(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("id"))
			{
				if(doc["id"].IsInt64())
					id = doc["id"].GetInt64();
				else
					std::cerr << Messages::field_does_not_contain_int64("id") << std::endl;
			}

			if(doc.HasMember("is_bot"))
			{
				if(doc["is_bot"].IsBool())
					is_bot = doc["is_bot"].GetBool();
				else
					std::cerr << Messages::field_does_not_contain_bool("is_bot") << std::endl;
			}

			if(doc.HasMember("first_name"))
			{
				if(doc["first_name"].IsString())
					first_name = doc["first_name"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("first_name") << std::endl;
			}

			if(doc.HasMember("last_name"))
			{
				if(doc["last_name"].IsString())
					last_name = doc["last_name"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("last_name") << std::endl;
			}

			if(doc.HasMember("username"))
			{
				if(doc["username"].IsString())
					username = doc["username"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("username") << std::endl;
			}

			if(doc.HasMember("language_code"))
			{
				if(doc["language_code"].IsString())
					language_code = doc["language_code"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("language_code") << std::endl;
			}

			if(doc.HasMember("can_join_groups"))
			{
				if(doc["can_join_groups"].IsBool())
					can_join_groups = doc["can_join_groups"].GetBool();
				else
					std::cerr << Messages::field_does_not_contain_bool("can_join_groups") << std::endl;
			}

			if(doc.HasMember("can_read_all_group_messages"))
			{
				if(doc["can_read_all_group_messages"].IsBool())
					can_read_all_group_messages = doc["can_read_all_group_messages"].GetBool();
				else
					std::cerr << Messages::field_does_not_contain_bool("can_read_all_group_messages") << std::endl;
			}

			if(doc.HasMember("supports_inline_queries"))
			{
				if(doc["supports_inline_queries"].IsBool())
					supports_inline_queries = doc["supports_inline_queries"].GetBool();
				else
					std::cerr << Messages::field_does_not_contain_bool("supports_inline_queries") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string User::parse_to_json() const noexcept
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
		json.append(", ");

		//field can_join_groups
		std::string can_join_groups_bool = can_join_groups ? "true" : "false";
		json.append("\"can_join_groups\": \"" + can_join_groups_bool + "\"");
		json.append(", ");

		//field can_read_all_group_messages
		std::string can_read_all_group_messages_bool = can_read_all_group_messages ? "true" : "false";
		json.append("\"can_read_all_group_messages\": \"" + can_read_all_group_messages_bool + "\"");
		json.append(", ");

		//field is_bot
		std::string supports_inline_queries_bool = supports_inline_queries ? "true" : "false";
		json.append("\"supports_inline_queries\": \"" + supports_inline_queries_bool + "\"");

		json.append("}");

		return json;
	}
}
