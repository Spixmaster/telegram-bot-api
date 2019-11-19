#include "tgbot/types/Location.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	Location::Location() : longitude(), latitude()
	{}

	Location::Location(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(Tools::is_json(json))
		{
			//assignments
			if(doc.HasMember("longitude"))
				longitude = doc["longitude"].GetFloat();

			if(doc.HasMember("latitude"))
				latitude = doc["latitude"].GetFloat();
		}
	}

	std::string Location::parse_to_json() const
	{
		std::string json = "{";

		//field longitude
		json.append("\"longitude\": " + std::to_string(longitude));
		json.append(", ");

		//field latitude
		json.append("\"latitude\": " + std::to_string(latitude));

		json.append("}");

		return json;
	}
}
