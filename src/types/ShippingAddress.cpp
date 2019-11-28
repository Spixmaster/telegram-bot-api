#include "tgbot/types/ShippingAddress.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	ShippingAddress::ShippingAddress() : country_code(), state(), city(), street_line1(), street_line2(), postcode()
	{}

	ShippingAddress::ShippingAddress(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("country_code"))
				country_code = doc["country_code"].GetString();

			if(doc.HasMember("state"))
				state = doc["state"].GetString();

			if(doc.HasMember("city"))
				city = doc["city"].GetString();

			if(doc.HasMember("street_line1"))
				street_line1 = doc["street_line1"].GetString();

			if(doc.HasMember("street_line2"))
				street_line2 = doc["street_line2"].GetString();

			if(doc.HasMember("postcode"))
				postcode = doc["postcode"].GetString();
		}
	}

	std::string ShippingAddress::parse_to_json() const
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

		//field postcode
		json.append("\"postcode\": \"" + postcode + "\"");

		json.append("}");

		return json;
	}
}
