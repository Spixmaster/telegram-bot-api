#include "tgbot/types/LabeledPrice.h"
#include "tools/Tools.h"
#include <iostream>

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
				if(doc["label"].IsString())
					label = doc["label"].GetString();
				else
					std::cerr << "Error: Field \"label\" does not contain a string." << std::endl;

			if(doc.HasMember("amount"))
				if(doc["amount"].IsInt())
					amount = doc["amount"].GetInt();
				else
					std::cerr << "Error: Field \"amount\" does not contain an int." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string LabeledPrice::parse_to_json() const
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
