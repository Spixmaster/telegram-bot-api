#include "tgbot/types/InputVenueMessageContent.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	InputVenueMessageContent::InputVenueMessageContent() : latitude(), longitude(), title(), address(), foursquare_id(), foursquare_type()
	{}

	InputVenueMessageContent::InputVenueMessageContent(const std::string &json)
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

			if(doc.HasMember("title"))
			{
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("title"));
			}

			if(doc.HasMember("address"))
			{
				if(doc["address"].IsString())
					address = doc["address"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("address"));
			}

			if(doc.HasMember("foursquare_id"))
			{
				if(doc["foursquare_id"].IsString())
					foursquare_id = doc["foursquare_id"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("foursquare_id"));
			}

			if(doc.HasMember("foursquare_type"))
			{
				if(doc["foursquare_type"].IsString())
					foursquare_type = doc["foursquare_type"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("foursquare_type"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string InputVenueMessageContent::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field latitude
		json.append("\"latitude\": " + std::to_string(latitude));
		json.append(", ");

		//Field longitude
		json.append("\"longitude\": " + std::to_string(longitude));
		json.append(", ");

		//Field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//Field address
		json.append("\"address\": \"" + address + "\"");
		json.append(", ");

		//Field foursquare_id
		json.append("\"foursquare_id\": \"" + foursquare_id + "\"");
		json.append(", ");

		//Field foursquare_type
		json.append("\"foursquare_type\": \"" + foursquare_type + "\"");

		json.append("}");

		return json;
	}
}
