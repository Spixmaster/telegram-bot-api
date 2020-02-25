#include "tgbot/types/LabeledPrice.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	LabeledPrice::LabeledPrice() : label(), amount()
	{}

	LabeledPrice::LabeledPrice(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("label"))
			{
				if(doc["label"].IsString())
					label = doc["label"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("label") << std::endl;
			}

			if(doc.HasMember("amount"))
			{
				if(doc["amount"].IsInt())
					amount = doc["amount"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("amount") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string LabeledPrice::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field label
		json.append("\"label\": \"" + label + "\"");
		json.append(", ");

		//field amount
		json.append("\"amount\": " + amount);

		json.append("}");

		return json;
	}
}
