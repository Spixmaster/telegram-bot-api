#include "tgbot/types/ShippingQuery.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

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
			//Assignments
			if(doc.HasMember("id"))
			{
				if(doc["id"].IsString())
					id = doc["id"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("id"));
			}

			if(doc.HasMember("from"))
			{
				if(doc["from"].IsObject())
					from = std::make_shared<User>(tools::Tools::get_json_as_string(doc["from"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("from"));
			}

			if(doc.HasMember("invoice_payload"))
			{
				if(doc["invoice_payload"].IsString())
					invoice_payload = doc["invoice_payload"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("invoice_payload"));
			}

			if(doc.HasMember("shipping_address"))
			{
				if(doc["shipping_address"].IsObject())
					shipping_address = std::make_shared<ShippingAddress>(tools::Tools::get_json_as_string(doc["shipping_address"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("shipping_address"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string ShippingQuery::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//Field from
		json.append("\"from\": " + from->parse_to_json());
		json.append(", ");

		//Field invoice_payload
		json.append("\"invoice_payload\": \"" + invoice_payload + "\"");
		json.append(", ");

		//Field shipping_address
		json.append("\"shipping_address\": " + shipping_address->parse_to_json());

		json.append("}");
		return json;
	}
}
