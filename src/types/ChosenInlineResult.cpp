#include "tgbot/types/ChosenInlineResult.h"
#include "tools/Tools.h"

namespace tgbot
{
	ChosenInlineResult::ChosenInlineResult() : result_id(), from(), location(), inline_message_id(), query()
	{}

	ChosenInlineResult::ChosenInlineResult(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("result_id"))
				result_id = doc["result_id"].GetString();

			if(doc.HasMember("from"))
				from = std::make_shared<User>(SpecialTools::get_json_as_string(doc["from"]));

			if(doc.HasMember("location"))
				location = std::make_shared<Location>(SpecialTools::get_json_as_string(doc["location"]));

			if(doc.HasMember("inline_message_id"))
				inline_message_id = doc["inline_message_id"].GetString();

			if(doc.HasMember("query"))
				query = doc["query"].GetString();
		}
	}

	std::string ChosenInlineResult::parse_to_json() const
	{
		std::string json = "{";

		//field result_id
		json.append("\"result_id\": \"" + result_id + "\"");
		json.append(", ");

		//field from
		json.append("\"from\": " + from->parse_to_json());
		json.append(", ");

		//field location
		json.append("\"location\": " + location->parse_to_json());
		json.append(", ");

		//field inline_message_id
		json.append("\"inline_message_id\": \"" + inline_message_id + "\"");
		json.append(", ");

		//field query
		json.append("\"query\": \"" + query + "\"");

		json.append("}");

		return json;
	}
}
