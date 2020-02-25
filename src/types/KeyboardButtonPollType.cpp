#include "tgbot/types/KeyboardButtonPollType.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

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
					std::cerr << Messages::field_does_not_contain_string("type") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string KeyboardButtonPollType::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field file_id
		json.append("\"type\": \"" + type + "\"");

		json.append("}");

		return json;
	}
}
