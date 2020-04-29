#include "tgbot/types/Dice.h"
#include <rapidjson/document.h>
#include "tgbot/constants/Messages.h"
#include <iostream>

namespace tgbot
{
	Dice::Dice() : emoji(), value()
	{}

	Dice::Dice(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("emoji"))
			{
				if(doc["emoji"].IsString())
					emoji = doc["emoji"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("emoji") << std::endl;
			}

			if(doc.HasMember("value"))
			{
				if(doc["value"].IsInt())
					value = doc["value"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("value") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string Dice::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field emoji
		json.append("\"emoji\": \"" + emoji + "\"");
		json.append(", ");

		//field value
		json.append("\"value\": \"" + std::to_string(value) + "\"");

		json.append("}");

		return json;
	}
}
