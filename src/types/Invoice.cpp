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
			//Assignments
			if(doc.HasMember("title"))
			{
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("title"));
			}

			if(doc.HasMember("description"))
			{
				if(doc["description"].IsString())
					description = doc["description"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("description"));
			}

			if(doc.HasMember("start_parameter"))
			{
				if(doc["start_parameter"].IsString())
					start_parameter = doc["start_parameter"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("start_parameter"));
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
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("total_amount"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string Invoice::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//Field description
		json.append("\"description\": \"" + description + "\"");
		json.append(", ");

		//Field start_parameter
		json.append("\"start_parameter\": \"" + start_parameter + "\"");
		json.append(", ");

		//Field currency
		json.append("\"currency\": \"" + currency + "\"");
		json.append(", ");

		//Field total_amount
		json.append("\"total_amount\": " + total_amount);

		json.append("}");

		return json;
	}
}
