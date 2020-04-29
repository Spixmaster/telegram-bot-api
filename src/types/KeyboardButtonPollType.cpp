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
			//Assignments
			if(doc.HasMember("type"))
			{
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("type"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string KeyboardButtonPollType::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field file_id
		json.append("\"type\": \"" + type + "\"");

		json.append("}");

		return json;
	}
}
