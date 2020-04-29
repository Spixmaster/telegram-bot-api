#include <rapidjson/document.h>
#include "tgbot/types/InputLocationMessageContent.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

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
			//Assignments
			if(doc.HasMember("latitude"))
			{
				if(doc["latitude"].IsFloat())
					latitude = doc["latitude"].GetFloat();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_float("latitude"));
			}

			if(doc.HasMember("longitude"))
			{
				if(doc["longitude"].IsFloat())
					longitude = doc["longitude"].GetFloat();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_float("longitude"));
			}

			if(doc.HasMember("live_period"))
			{
				if(doc["live_period"].IsInt())
					live_period = doc["live_period"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("live_period"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string InputLocationMessageContent::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field latitude
		json.append("\"latitude\": " + std::to_string(latitude));
		json.append(", ");

		//Field longitude
		json.append("\"longitude\": " + std::to_string(longitude));
		json.append(", ");

		//Field live_period
		json.append("\"live_period\": " + live_period);

		json.append("}");
		return json;
	}
}
