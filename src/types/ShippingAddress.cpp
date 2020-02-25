#include "tgbot/types/ShippingAddress.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

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
					std::cerr << Messages::field_does_not_contain_string("country_code") << std::endl;
			}

			if(doc.HasMember("state"))
			{
				if(doc["state"].IsString())
					state = doc["state"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("state") << std::endl;
			}

			if(doc.HasMember("city"))
			{
				if(doc["city"].IsString())
					city = doc["city"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("city") << std::endl;
			}

			if(doc.HasMember("street_line1"))
			{
				if(doc["street_line1"].IsString())
					street_line1 = doc["street_line1"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("street_line1") << std::endl;
			}

			if(doc.HasMember("street_line2"))
			{
				if(doc["street_line2"].IsString())
					street_line2 = doc["street_line2"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("street_line2") << std::endl;
			}

			if(doc.HasMember("post_code"))
			{
				if(doc["post_code"].IsString())
					post_code = doc["post_code"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("post_code") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
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
