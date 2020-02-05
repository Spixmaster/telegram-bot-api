#include <rapidjson/document.h>
#include "tgbot/types/Invoice.h"
#include "tools/Tools.h"
#include <iostream>

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
					std::cerr << "Error: Field \"title\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("description"))
			{
				if(doc["description"].IsString())
					description = doc["description"].GetString();
				else
					std::cerr << "Error: Field \"description\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("start_parameter"))
			{
				if(doc["start_parameter"].IsString())
					start_parameter = doc["start_parameter"].GetString();
				else
					std::cerr << "Error: Field \"start_parameter\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("currency"))
			{
				if(doc["currency"].IsString())
					currency = doc["currency"].GetString();
				else
					std::cerr << "Error: Field \"currency\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("total_amount"))
			{
				if(doc["total_amount"].IsInt())
					total_amount = doc["total_amount"].GetInt();
				else
					std::cerr << "Error: Field \"total_amount\" does not contain an int." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
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
