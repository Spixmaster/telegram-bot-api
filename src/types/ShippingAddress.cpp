#include "tgbot/types/ShippingAddress.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	ShippingAddress::ShippingAddress() : country_code(), state(), city(), street_line1(), street_line2(), post_code()
	{}

	ShippingAddress::ShippingAddress(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("country_code"))
			{
				if(doc["country_code"].IsString())
					country_code = doc["country_code"].GetString();
				else
					std::cerr << "Error: Field \"country_code\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("state"))
			{
				if(doc["state"].IsString())
					state = doc["state"].GetString();
				else
					std::cerr << "Error: Field \"state\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("city"))
			{
				if(doc["city"].IsString())
					city = doc["city"].GetString();
				else
					std::cerr << "Error: Field \"city\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("street_line1"))
			{
				if(doc["street_line1"].IsString())
					street_line1 = doc["street_line1"].GetString();
				else
					std::cerr << "Error: Field \"street_line1\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("street_line2"))
			{
				if(doc["street_line2"].IsString())
					street_line2 = doc["street_line2"].GetString();
				else
					std::cerr << "Error: Field \"street_line2\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("post_code"))
			{
				if(doc["post_code"].IsString())
					post_code = doc["post_code"].GetString();
				else
					std::cerr << "Error: Field \"post_code\" does not contain a string." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string ShippingAddress::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field country_code
		json.append("\"country_code\": \"" + country_code + "\"");
		json.append(", ");

		//field state
		json.append("\"state\": \"" + state + "\"");
		json.append(", ");

		//field city
		json.append("\"city\": \"" + city + "\"");
		json.append(", ");

		//field street_line1
		json.append("\"street_line1\": \"" + street_line1 + "\"");
		json.append(", ");

		//field street_line2
		json.append("\"street_line2\": \"" + street_line2 + "\"");
		json.append(", ");

		//field post_code
		json.append("\"post_code\": \"" + post_code + "\"");

		json.append("}");

		return json;
	}
}
