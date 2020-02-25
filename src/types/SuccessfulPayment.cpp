#include "tgbot/types/SuccessfulPayment.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

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
			{
				if(doc["currency"].IsString())
					currency = doc["currency"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("currency") << std::endl;
			}

			if(doc.HasMember("total_amount"))
			{
				if(doc["total_amount"].IsInt())
					total_amount = doc["total_amount"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("total_amount") << std::endl;
			}

			if(doc.HasMember("invoice_payload"))
			{
				if(doc["invoice_payload"].IsString())
					invoice_payload = doc["invoice_payload"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("total_amount") << std::endl;
			}

			if(doc.HasMember("shipping_option_id"))
			{
				if(doc["shipping_option_id"].IsString())
					shipping_option_id = doc["shipping_option_id"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("shipping_option_id") << std::endl;
			}

			if(doc.HasMember("order_info"))
			{
				if(doc["order_info"].IsObject())
					order_info = std::make_shared<OrderInfo>(tools::Tools::get_json_as_string(doc["order_info"]));
				else
					std::cerr << Messages::field_does_not_contain_json_obj("order_info") << std::endl;
			}

			if(doc.HasMember("telegram_payment_charge_id"))
			{
				if(doc["telegram_payment_charge_id"].IsString())
					telegram_payment_charge_id = doc["telegram_payment_charge_id"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("telegram_payment_charge_id") << std::endl;
			}

			if(doc.HasMember("provider_payment_charge_id"))
			{
				if(doc["provider_payment_charge_id"].IsString())
					provider_payment_charge_id = doc["provider_payment_charge_id"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("provider_payment_charge_id") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string SuccessfulPayment::parse_to_json() const noexcept
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
