#include "tgbot/types/Venue.h"
#include "tools/Tools.h"
#include <iostream>

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
			{
				if(doc["location"].IsObject())
					location = std::make_shared<Location>(tools::Tools::get_json_as_string(doc["location"]));
				else
					std::cerr << "Error: Field \"location\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("title"))
			{
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					std::cerr << "Error: Field \"title\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("address"))
			{
				if(doc["address"].IsString())
					address = doc["address"].GetString();
				else
					std::cerr << "Error: Field \"address\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("foursquare_id"))
			{
				if(doc["foursquare_id"].IsString())
					foursquare_id = doc["foursquare_id"].GetString();
				else
					std::cerr << "Error: Field \"foursquare_id\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("foursquare_type"))
			{
				if(doc["foursquare_type"].IsString())
					foursquare_type = doc["foursquare_type"].GetString();
				else
					std::cerr << "Error: Field \"foursquare_type\" does not contain a string." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
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
