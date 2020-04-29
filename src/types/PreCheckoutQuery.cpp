#include "tgbot/types/PreCheckoutQuery.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	PreCheckoutQuery::PreCheckoutQuery() : id(), from(), currency(), total_amount(), invoice_payload(), shipping_option_id(), order_info()
	{}

	PreCheckoutQuery::PreCheckoutQuery(const std::string &json)
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

			if(doc.HasMember("currency"))
			{
				if(doc["currency"].IsString())
					currency = doc["currency"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("currency"));
			}

			if(doc.HasMember("total_amount"))
			{
				if(doc["total_amount"].IsInt())
					total_amount = doc["total_amount"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("total_amounttotal_amount"));
			}

			if(doc.HasMember("invoice_payload"))
			{
				if(doc["invoice_payload"].IsString())
					invoice_payload = doc["invoice_payload"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("invoice_payload"));
			}

			if(doc.HasMember("shipping_option_id"))
			{
				if(doc["shipping_option_id"].IsString())
					shipping_option_id = doc["shipping_option_id"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("shipping_option_id"));
			}

			if(doc.HasMember("order_info"))
			{
				if(doc["order_info"].IsObject())
					order_info = std::make_shared<OrderInfo>(tools::Tools::get_json_as_string(doc["order_info"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("order_info"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string PreCheckoutQuery::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//Field from
		json.append("\"from\": " + from->parse_to_json());
		json.append(", ");

		//Field currency
		json.append("\"currency\": \"" + currency + "\"");
		json.append(", ");

		//Field total_amount
		json.append("\"total_amount\": " + total_amount);
		json.append(", ");

		//Field invoice_payload
		json.append("\"invoice_payload\": \"" + invoice_payload + "\"");
		json.append(", ");

		//Field shipping_option_id
		json.append("\"shipping_option_id\": \"" + shipping_option_id + "\"");
		json.append(", ");

		//Field order_info
		json.append("\"order_info\": " + order_info->parse_to_json());

		json.append("}");

		return json;
	}
}
