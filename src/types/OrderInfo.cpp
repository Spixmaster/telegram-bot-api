#include "tgbot/types/OrderInfo.h"

namespace tgbot
{
	OrderInfo::OrderInfo() : name(), phone_number(), email(), shipping_address()
	{}

	OrderInfo::OrderInfo(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("name"))
			name = doc["name"].GetString();

		if(doc.HasMember("phone_number"))
			phone_number = doc["phone_number"].GetString();

		if(doc.HasMember("email"))
			email = doc["email"].GetString();

		if(doc.HasMember("shipping_address"))
			shipping_address = std::make_shared<ShippingAddress>(SpecialTools::get_json_obj_as_string(doc["shipping_address"]));
	}

	std::string OrderInfo::parse_to_json() const
	{
		std::string json = "{";

		//field name
		json.append("\"name\": \"" + name + "\"");
		json.append(", ");

		//field phone_number
		json.append("\"phone_number\": \"" + phone_number + "\"");
		json.append(", ");

		//field email
		json.append("\"email\": \"" + email + "\"");
		json.append(", ");

		//field shipping_address
		json.append("\"shipping_address\": " + shipping_address->parse_to_json());


		json.append("}");

		return json;
	}
}
