#include "tgbot/types/ShippingQuery.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	ShippingQuery::ShippingQuery() : id(), from(), invoice_payload(), shipping_address()
	{}

	ShippingQuery::ShippingQuery(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("id"))
			{
				if(doc["id"].IsString())
					id = doc["id"].GetString();
				else
					std::cerr << "Error: Field \"id\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("from"))
			{
				if(doc["from"].IsObject())
					from = std::make_shared<User>(tools::Tools::get_json_as_string(doc["from"]));
				else
					std::cerr << "Error: Field \"from\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("invoice_payload"))
			{
				if(doc["invoice_payload"].IsString())
					invoice_payload = doc["invoice_payload"].GetString();
				else
					std::cerr << "Error: Field \"invoice_payload\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("shipping_address"))
			{
				if(doc["shipping_address"].IsObject())
					shipping_address = std::make_shared<ShippingAddress>(tools::Tools::get_json_as_string(doc["shipping_address"]));
				else
					std::cerr << "Error: Field \"shipping_address\" does not contain a json object." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string ShippingQuery::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//field from
		json.append("\"from\": " + from->parse_to_json());
		json.append(", ");

		//field invoice_payload
		json.append("\"invoice_payload\": \"" + invoice_payload + "\"");
		json.append(", ");

		//field shipping_address
		json.append("\"shipping_address\": " + shipping_address->parse_to_json());

		json.append("}");

		return json;
	}
}
