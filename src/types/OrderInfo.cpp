#include "tgbot/types/OrderInfo.h"
#include "tools/Tools.h"
#include <iostream>

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
			//assignments
			if(doc.HasMember("name"))
				if(doc["name"].IsString())
					name = doc["name"].GetString();
				else
					std::cerr << "Error: Field \"name\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"name\"." << std::endl;

			if(doc.HasMember("phone_number"))
				if(doc["phone_number"].IsString())
					phone_number = doc["phone_number"].GetString();
				else
					std::cerr << "Error: Field \"phone_number\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"phone_number\"." << std::endl;

			if(doc.HasMember("email"))
				if(doc["email"].IsString())
					email = doc["email"].GetString();
				else
					std::cerr << "Error: Field \"email\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"email\"." << std::endl;

			if(doc.HasMember("shipping_address"))
				if(doc["shipping_address"].IsObject())
					shipping_address = std::make_shared<ShippingAddress>(tools::Tools::get_json_as_string(doc["shipping_address"]));
				else
					std::cerr << "Error: Field \"shipping_address\" does not contain a json object." << std::endl;
			else
				std::cerr << "Error: There is no field \"shipping_address\"." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
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
