#include <rapidjson/document.h>
#include "tgbot/types/Invoice.h"
#include "tools/Tools.h"

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
				title = doc["title"].GetString();

			if(doc.HasMember("description"))
				description = doc["description"].GetString();

			if(doc.HasMember("start_parameter"))
				start_parameter = doc["start_parameter"].GetString();

			if(doc.HasMember("currency"))
				currency = doc["currency"].GetString();

			if(doc.HasMember("total_amount"))
				total_amount = doc["total_amount"].GetInt();
		}
	}

	std::string Invoice::parse_to_json() const
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
