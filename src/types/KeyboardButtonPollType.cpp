#include "tgbot/types/KeyboardButtonPollType.h"
#include <iostream>

namespace tgbot
{
	KeyboardButtonPollType::KeyboardButtonPollType() : type()
	{}

	KeyboardButtonPollType::KeyboardButtonPollType(const std::string &json)
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
					std::cerr << "Error: Field \"type\" does not contain a string." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string KeyboardButtonPollType::parse_to_json() const
	{
		std::string json = "{";

		//field file_id
		json.append("\"type\": \"" + type + "\"");

		json.append("}");

		return json;
	}
}
