#include <rapidjson/document.h>
#include "tgbot/types/PollOption.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	PollOption::PollOption() : text(), voter_count()
	{}

	PollOption::PollOption(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("text"))
			{
				if(doc["text"].IsString())
					text = doc["text"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("text") << std::endl;
			}

			if(doc.HasMember("voter_count"))
			{
				if(doc["voter_count"].IsInt())
					voter_count = doc["voter_count"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("voter_count") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string PollOption::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field text
		json.append("\"text\": \"" + text + "\"");
		json.append(", ");

		//field voter_count
		json.append("\"voter_count\": " + voter_count);

		json.append("}");

		return json;
	}
}

