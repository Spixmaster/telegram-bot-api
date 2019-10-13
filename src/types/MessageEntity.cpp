#include "tgbot/types/MessageEntity.h"

namespace tgbot
{
	MessageEntity::MessageEntity() : type(), offset(), length(), url(), user()
	{}

	MessageEntity::MessageEntity(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("type"))
			type = doc["type"].GetString();

		if(doc.HasMember("offset"))
			offset = doc["offset"].GetInt();

		if(doc.HasMember("length"))
			length = doc["length"].GetInt();

		if(doc.HasMember("url"))
			url = doc["url"].GetString();

		if(doc.HasMember("user"))
			user = std::make_shared<User>(SpecialTools::get_json_obj_as_string(doc["user"]));
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

		json.append("}");

		return json;
	}
}
