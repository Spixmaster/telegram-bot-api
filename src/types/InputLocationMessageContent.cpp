#include <rapidjson/document.h>
#include "tgbot/types/InputLocationMessageContent.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	InputLocationMessageContent::InputLocationMessageContent() : latitude(), longitude(), live_period()
	{}

	InputLocationMessageContent::InputLocationMessageContent(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("latitude"))
			{
				if(doc["latitude"].IsFloat())
					latitude = doc["latitude"].GetFloat();
				else
					std::cerr << "Error: Field \"latitude\" does not contain a float." << std::endl;
			}

			if(doc.HasMember("longitude"))
			{
				if(doc["longitude"].IsFloat())
					longitude = doc["longitude"].GetFloat();
				else
					std::cerr << "Error: Field \"longitude\" does not contain a float." << std::endl;
			}

			if(doc.HasMember("live_period"))
			{
				if(doc["live_period"].IsInt())
					live_period = doc["live_period"].GetInt();
				else
					std::cerr << "Error: Field \"live_period\" does not contain an int." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string InputLocationMessageContent::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field latitude
		json.append("\"latitude\": " + std::to_string(latitude));
		json.append(", ");

		//field longitude
		json.append("\"longitude\": " + std::to_string(longitude));
		json.append(", ");

		//field live_period
		json.append("\"live_period\": " + live_period);

		json.append("}");

		return json;
	}
}
