#include <rapidjson/document.h>
#include "tgbot/types/PollOption.h"

namespace tgbot
{
	PollOption::PollOption() : text(), voter_count()
	{}

	PollOption::PollOption(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("text"))
			text = doc["text"].GetString();

		if(doc.HasMember("voter_count"))
			voter_count = doc["voter_count"].GetInt();
	}

	std::string PollOption::parse_to_json() const
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

