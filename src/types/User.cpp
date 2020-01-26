#include "tgbot/types/User.h"
#include <rapidjson/document.h>
#include "tools/Tools.h"
#include <iostream>

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
				if(doc["id"].IsInt())
					id = doc["id"].GetInt();
				else
					std::cerr << "Error: Field \"id\" does not contain an int." << std::endl;

			if(doc.HasMember("is_bot"))
				if(doc["is_bot"].IsBool())
					is_bot = doc["is_bot"].GetBool();
				else
					std::cerr << "Error: Field \"is_bot\" does not contain a bool." << std::endl;

			if(doc.HasMember("first_name"))
				if(doc["first_name"].IsString())
					first_name = doc["first_name"].GetString();
				else
					std::cerr << "Error: Field \"first_name\" does not contain a string." << std::endl;

			if(doc.HasMember("last_name"))
				if(doc["last_name"].IsString())
					last_name = doc["last_name"].GetString();
				else
					std::cerr << "Error: Field \"last_name\" does not contain a string." << std::endl;

			if(doc.HasMember("username"))
				if(doc["username"].IsString())
					username = doc["username"].GetString();
				else
					std::cerr << "Error: Field \"username\" does not contain a string." << std::endl;

			if(doc.HasMember("language_code"))
				if(doc["language_code"].IsString())
					language_code = doc["language_code"].GetString();
				else
					std::cerr << "Error: Field \"language_code\" does not contain a string." << std::endl;

			if(doc.HasMember("can_join_groups"))
				if(doc["can_join_groups"].IsBool())
					can_join_groups = doc["can_join_groups"].GetBool();
				else
					std::cerr << "Error: Field \"can_join_groups\" does not contain a bool." << std::endl;

			if(doc.HasMember("can_read_all_group_messages"))
				if(doc["can_read_all_group_messages"].IsBool())
					can_read_all_group_messages = doc["can_read_all_group_messages"].GetBool();
				else
					std::cerr << "Error: Field \"can_read_all_group_messages\" does not contain a bool." << std::endl;

			if(doc.HasMember("supports_inline_queries"))
				if(doc["supports_inline_queries"].IsBool())
					supports_inline_queries = doc["supports_inline_queries"].GetBool();
				else
					std::cerr << "Error: Field \"supports_inline_queries\" does not contain a bool." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
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
