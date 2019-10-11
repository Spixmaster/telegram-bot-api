#include "tgbot/types/LabeledPrice.h"

namespace tgbot
{
	LabeledPrice::LabeledPrice() : label(), amount()
	{}

	LabeledPrice::LabeledPrice(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("label"))
			label = doc["label"].GetString();

		if(doc.HasMember("amount"))
			amount = doc["amount"].GetInt();
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
