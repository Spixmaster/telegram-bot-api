#include "tgbot/types/Venue.h"
#include "tools/Tools.h"

namespace tgbot
{
	Venue::Venue() : location(), title(), address(), foursquare_id(), foursquare_type()
	{}

	Venue::Venue(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("location"))
				location = std::make_shared<Location>(tools::Tools::get_json_as_string(doc["location"]));

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

	std::string Venue::parse_to_json() const
	{
		std::string json = "{";

		//field location
		json.append("\"location\": " + location->parse_to_json());
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
