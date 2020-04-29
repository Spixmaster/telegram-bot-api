#include "tgbot/types/MessageEntity.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	MessageEntity::MessageEntity() : type(), offset(), length(), url(), user(), language()
	{}

	MessageEntity::MessageEntity(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//Assignments
			if(doc.HasMember("type"))
			{
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("type"));
			}

			if(doc.HasMember("offset"))
			{
				if(doc["offset"].IsInt())
					offset = doc["offset"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("offset"));
			}

			if(doc.HasMember("length"))
			{
				if(doc["length"].IsInt())
					length = doc["length"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("length"));
			}

			if(doc.HasMember("url"))
			{
				if(doc["url"].IsString())
					url = doc["url"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("url"));
			}

			if(doc.HasMember("user"))
			{
				if(doc["user"].IsObject())
					user = std::make_shared<User>(tools::Tools::get_json_as_string(doc["user"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("user"));
			}

			if(doc.HasMember("language"))
			{
				if(doc["language"].IsString())
					language = doc["language"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("language"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string MessageEntity::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//Field offset
		json.append("\"offset\": " + offset);
		json.append(", ");

		//Field length
		json.append("\"length\": " + length);
		json.append(", ");

		//Field url
		json.append("\"url\": \"" + url + "\"");
		json.append(", ");

		//Field user
		json.append("\"user\": " + user->parse_to_json());
		json.append(", ");

		//Field type
		json.append("\"language\": \"" + language + "\"");

		json.append("}");

		return json;
	}
}
