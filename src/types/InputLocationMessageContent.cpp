#include <rapidjson/document.h>
#include "tgbot/types/InputLocationMessageContent.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	InputLocationMessageContent::InputLocationMessageContent() : latitude(), longitude(), live_period()
	{}

	InputLocationMessageContent::InputLocationMessageContent(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(Tools::is_json(json))
		{
			//assignments
			if(doc.HasMember("latitude"))
				latitude = doc["latitude"].GetFloat();

			if(doc.HasMember("longitude"))
				longitude = doc["longitude"].GetFloat();

			if(doc.HasMember("live_period"))
				live_period = doc["live_period"].GetInt();
		}
	}

	std::string InputLocationMessageContent::parse_to_json() const
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
