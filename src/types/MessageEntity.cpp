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
			//assignments
			if(doc.HasMember("type"))
			{
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("type") << std::endl;
			}

			if(doc.HasMember("offset"))
			{
				if(doc["offset"].IsInt())
					offset = doc["offset"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("offset") << std::endl;
			}

			if(doc.HasMember("length"))
			{
				if(doc["length"].IsInt())
					length = doc["length"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("length") << std::endl;
			}

			if(doc.HasMember("url"))
			{
				if(doc["url"].IsString())
					url = doc["url"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("url") << std::endl;
			}

			if(doc.HasMember("user"))
			{
				if(doc["user"].IsObject())
					user = std::make_shared<User>(tools::Tools::get_json_as_string(doc["user"]));
				else
					std::cerr << Messages::field_does_not_contain_json_obj("user") << std::endl;
			}

			if(doc.HasMember("language"))
			{
				if(doc["language"].IsString())
					language = doc["language"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("language") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string MessageEntity::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field offset
		json.append("\"offset\": " + offset);
		json.append(", ");

		//field length
		json.append("\"length\": " + length);
		json.append(", ");

		//field url
		json.append("\"url\": \"" + url + "\"");
		json.append(", ");

		//field user
		json.append("\"user\": " + user->parse_to_json());
		json.append(", ");

		//field type
		json.append("\"language\": \"" + language + "\"");

		json.append("}");

		return json;
	}
}
