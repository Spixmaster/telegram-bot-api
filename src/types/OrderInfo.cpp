#include "tgbot/types/OrderInfo.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	OrderInfo::OrderInfo() : name(), phone_number(), email(), shipping_address()
	{}

	OrderInfo::OrderInfo(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//Assignments
			if(doc.HasMember("name"))
			{
				if(doc["name"].IsString())
					name = doc["name"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("name"));
			}

			if(doc.HasMember("phone_number"))
			{
				if(doc["phone_number"].IsString())
					phone_number = doc["phone_number"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("phone_number"));
			}

			if(doc.HasMember("email"))
			{
				if(doc["email"].IsString())
					email = doc["email"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("email"));
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

	std::string OrderInfo::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field name
		json.append("\"name\": \"" + name + "\"");
		json.append(", ");

		//Field phone_number
		json.append("\"phone_number\": \"" + phone_number + "\"");
		json.append(", ");

		//Field email
		json.append("\"email\": \"" + email + "\"");
		json.append(", ");

		//Field shipping_address
		json.append("\"shipping_address\": " + shipping_address->parse_to_json());

		json.append("}");
		return json;
	}
}
