#include <rapidjson/document.h>
#include "tgbot/types/PollOption.h"
#include "tools/Tools.h"
#include <iostream>

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
				if(doc["text"].IsString())
					text = doc["text"].GetString();
				else
					std::cerr << "Error: Field \"text\" does not contain a string." << std::endl;

			if(doc.HasMember("voter_count"))
				if(doc["voter_count"].IsInt())
					voter_count = doc["voter_count"].GetInt();
				else
					std::cerr << "Error: Field \"voter_count\" does not contain an int." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
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

