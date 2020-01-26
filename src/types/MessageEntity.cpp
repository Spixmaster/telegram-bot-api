#include "tgbot/types/MessageEntity.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	MessageEntity::MessageEntity() : type(), offset(), length(), url(), user()
	{}

	MessageEntity::MessageEntity(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("type"))
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					std::cerr << "Error: Field \"type\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"type\"." << std::endl;

			if(doc.HasMember("offset"))
				if(doc["offset"].IsInt())
					offset = doc["offset"].GetInt();
				else
					std::cerr << "Error: Field \"offset\" does not contain an int." << std::endl;
			else
				std::cerr << "Error: There is no field \"offset\"." << std::endl;

			if(doc.HasMember("length"))
				if(doc["length"].IsInt())
					length = doc["length"].GetInt();
				else
					std::cerr << "Error: Field \"length\" does not contain an int." << std::endl;
			else
				std::cerr << "Error: There is no field \"length\"." << std::endl;

			if(doc.HasMember("url"))
				if(doc["url"].IsString())
					url = doc["url"].GetString();
				else
					std::cerr << "Error: Field \"url\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"url\"." << std::endl;

			if(doc.HasMember("user"))
				user = std::make_shared<User>(tools::Tools::get_json_as_string(doc["user"]));
			if(doc.HasMember("user"))
				if(doc["user"].IsObject())
					user = std::make_shared<User>(tools::Tools::get_json_as_string(doc["user"]));
				else
					std::cerr << "Error: Field \"user\" does not contain a json object." << std::endl;
			else
				std::cerr << "Error: There is no field \"user\"." << std::endl;

			if(doc.HasMember("language"))
				if(doc["language"].IsString())
					language = doc["language"].GetString();
				else
					std::cerr << "Error: Field \"language\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"language\"." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string MessageEntity::parse_to_json() const
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
