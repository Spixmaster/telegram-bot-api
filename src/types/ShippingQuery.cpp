#include "tgbot/types/ShippingQuery.h"
#include "tools/Tools.h"

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
				id = doc["id"].GetString();

			if(doc.HasMember("from"))
				from = std::make_shared<User>(tools::Tools::get_json_as_string(doc["from"]));

			if(doc.HasMember("invoice_payload"))
				invoice_payload = doc["invoice_payload"].GetString();

			if(doc.HasMember("shipping_address"))
				shipping_address = std::make_shared<ShippingAddress>(tools::Tools::get_json_as_string(doc["shipping_address"]));
		}
	}

	std::string ShippingQuery::parse_to_json() const
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
