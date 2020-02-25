#include <rapidjson/document.h>
#include "tgbot/types/Invoice.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	Invoice::Invoice() : title(), description(), start_parameter(), currency(), total_amount()
	{}

	Invoice::Invoice(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("title"))
			{
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("title") << std::endl;
			}

			if(doc.HasMember("description"))
			{
				if(doc["description"].IsString())
					description = doc["description"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("description") << std::endl;
			}

			if(doc.HasMember("start_parameter"))
			{
				if(doc["start_parameter"].IsString())
					start_parameter = doc["start_parameter"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("start_parameter") << std::endl;
			}

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
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string Invoice::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//field description
		json.append("\"description\": \"" + description + "\"");
		json.append(", ");

		//field start_parameter
		json.append("\"start_parameter\": \"" + start_parameter + "\"");
		json.append(", ");

		//field currency
		json.append("\"currency\": \"" + currency + "\"");
		json.append(", ");

		//field total_amount
		json.append("\"total_amount\": " + total_amount);

		json.append("}");

		return json;
	}
}
