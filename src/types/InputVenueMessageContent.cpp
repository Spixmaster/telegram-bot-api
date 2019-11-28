#include "tgbot/types/InputVenueMessageContent.h"
#include "tgbot/Tools.h"

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
			//assignments
			if(doc.HasMember("latitude"))
				latitude = doc["latitude"].GetFloat();

			if(doc.HasMember("longitude"))
				longitude = doc["longitude"].GetFloat();

			if(doc.HasMember("title"))
				title = doc["title"].GetString();

			if(doc.HasMember("address"))
				address = doc["address"].GetString();

			if(doc.HasMember("foursquare_id"))
				foursquare_id = doc["foursquare_id"].GetString();

			if(doc.HasMember("foursquare_type"))
				foursquare_type = doc["foursquare_type"].GetString();
		}
	}

	std::string InputVenueMessageContent::parse_to_json() const
	{
		std::string json = "{";

		//field latitude
		json.append("\"latitude\": " + std::to_string(latitude));
		json.append(", ");

		//field longitude
		json.append("\"longitude\": " + std::to_string(longitude));
		json.append(", ");

		//field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//field address
		json.append("\"address\": \"" + address + "\"");
		json.append(", ");

		//field foursquare_id
		json.append("\"foursquare_id\": \"" + foursquare_id + "\"");
		json.append(", ");

		//field foursquare_type
		json.append("\"foursquare_type\": \"" + foursquare_type + "\"");

		json.append("}");

		return json;
	}
}
