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
			//Assignments
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
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("total_amount"));
			}

			if(doc.HasMember("invoice_payload"))
			{
				if(doc["invoice_payload"].IsString())
					invoice_payload = doc["invoice_payload"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("total_amount"));
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

			if(doc.HasMember("telegram_payment_charge_id"))
			{
				if(doc["telegram_payment_charge_id"].IsString())
					telegram_payment_charge_id = doc["telegram_payment_charge_id"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("telegram_payment_charge_id"));
			}

			if(doc.HasMember("provider_payment_charge_id"))
			{
				if(doc["provider_payment_charge_id"].IsString())
					provider_payment_charge_id = doc["provider_payment_charge_id"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("provider_payment_charge_id"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string SuccessfulPayment::parse_to_json() const noexcept
	{
		std::string json = "{";

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
		json.append(", ");

		//Field telegram_payment_charge_id
		json.append("\"telegram_payment_charge_id\": \"" + telegram_payment_charge_id + "\"");
		json.append(", ");

		//Field provider_payment_charge_id
		json.append("\"provider_payment_charge_id\": \"" + provider_payment_charge_id + "\"");

		json.append("}");

		return json;
	}
}
