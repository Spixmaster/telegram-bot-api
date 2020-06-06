#include "tgbot/types/Dice.h"
#include <rapidjson/document.h>
#include "tgbot/constants/Messages.h"
#include <iostream>
#include "tools/Tools.h"

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
			//Assignments
			if(doc.HasMember("emoji"))
			{
				if(doc["emoji"].IsString())
					emoji = doc["emoji"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("emoji"));
			}

			if(doc.HasMember("value"))
			{
				if(doc["value"].IsInt())
					value = doc["value"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("value"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string Dice::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field emoji
		json.append("\"emoji\": \"" + emoji + "\"");
		json.append(", ");

		//Field value
		json.append("\"value\": " + value);

		json.append("}");
		return json;
	}
}
