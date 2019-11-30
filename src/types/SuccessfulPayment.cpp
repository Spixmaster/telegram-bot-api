#include "tgbot/types/SuccessfulPayment.h"
#include "tools/Tools.h"

namespace tgbot
{
	SuccessfulPayment::SuccessfulPayment() : currency(), total_amount(), invoice_payload(), shipping_option_id(), order_info(), telegram_payment_charge_id(),
			provider_payment_charge_id()
	{}

	SuccessfulPayment::SuccessfulPayment(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("currency"))
				currency = doc["currency"].GetString();

			if(doc.HasMember("total_amount"))
				total_amount = doc["total_amount"].GetInt();

			if(doc.HasMember("invoice_payload"))
				invoice_payload = doc["invoice_payload"].GetString();

			if(doc.HasMember("shipping_option_id"))
				shipping_option_id = doc["shipping_option_id"].GetString();

			if(doc.HasMember("order_info"))
				order_info = std::make_shared<OrderInfo>(SpecialTools::get_json_as_string(doc["order_info"]));

			if(doc.HasMember("telegram_payment_charge_id"))
				telegram_payment_charge_id = doc["telegram_payment_charge_id"].GetString();

			if(doc.HasMember("provider_payment_charge_id"))
				provider_payment_charge_id = doc["provider_payment_charge_id"].GetString();
		}
	}

	std::string SuccessfulPayment::parse_to_json() const
	{
		std::string json = "{";

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
		json.append(", ");

		//field telegram_payment_charge_id
		json.append("\"telegram_payment_charge_id\": \"" + telegram_payment_charge_id + "\"");
		json.append(", ");

		//field provider_payment_charge_id
		json.append("\"provider_payment_charge_id\": \"" + provider_payment_charge_id + "\"");

		json.append("}");

		return json;
	}
}
