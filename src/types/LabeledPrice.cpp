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
			//Assignments
			if(doc.HasMember("label"))
			{
				if(doc["label"].IsString())
					label = doc["label"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("label"));
			}

			if(doc.HasMember("amount"))
			{
				if(doc["amount"].IsInt())
					amount = doc["amount"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("amount"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string LabeledPrice::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field label
		json.append("\"label\": \"" + label + "\"");
		json.append(", ");

		//Field amount
		json.append("\"amount\": " + amount);

		json.append("}");
		return json;
	}
}
