#include "tgbot/types/PreCheckoutQuery.h"

namespace tgbot
{
	PreCheckoutQuery::PreCheckoutQuery() : id(), from(), currency(), total_amount(), invoice_payload(), shipping_option_id(), order_info()
	{}

	PreCheckoutQuery::PreCheckoutQuery(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("id"))
			id = doc["id"].GetString();

		if(doc.HasMember("from"))
			from = std::make_shared<User>(SpecialTools::get_json_obj_as_string(doc["from"]));

		if(doc.HasMember("currency"))
			currency = doc["currency"].GetString();

		if(doc.HasMember("total_amount"))
			total_amount = doc["total_amount"].GetInt();

		if(doc.HasMember("invoice_payload"))
			invoice_payload = doc["invoice_payload"].GetString();

		if(doc.HasMember("shipping_option_id"))
			shipping_option_id = doc["shipping_option_id"].GetString();

		if(doc.HasMember("order_info"))
			order_info = std::make_shared<OrderInfo>(SpecialTools::get_json_obj_as_string(doc["order_info"]));
	}

	std::string PreCheckoutQuery::parse_to_json() const
	{
		std::string json = "{";

		//field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//field from
		json.append("\"from\": " + from->parse_to_json());
		json.append(", ");

		//field currency
		json.append("\"currency\": \"" + currency + "\"");
		json.append(", ");

		//field total_amount
		json.append("\"total_amount\": " + total_amount);
		json.append(", ");

		//field invoice_payload
		json.append("\"invoice_payload\": \"" + invoice_payload + "\"");
		json.append(", ");

		//field shipping_option_id
		json.append("\"shipping_option_id\": \"" + shipping_option_id + "\"");
		json.append(", ");

		//field order_info
		json.append("\"order_info\": " + order_info->parse_to_json());

		json.append("}");

		return json;
	}
}
