#include "tgbot/types/Location.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	Location::Location() : longitude(), latitude()
	{}

	Location::Location(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//Assignments
			if(doc.HasMember("longitude"))
			{
				if(doc["longitude"].IsFloat())
					longitude = doc["longitude"].GetFloat();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_float("longitude"));
			}

			if(doc.HasMember("latitude"))
			{
				if(doc["latitude"].IsFloat())
					latitude = doc["latitude"].GetFloat();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_float("latitude"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string Location::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field longitude
		json.append("\"longitude\": " + std::to_string(longitude));
		json.append(", ");

		//Field latitude
		json.append("\"latitude\": " + std::to_string(latitude));

		json.append("}");
		return json;
	}
}
