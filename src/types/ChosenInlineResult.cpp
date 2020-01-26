#include "tgbot/types/ChosenInlineResult.h"
#include "tools/Tools.h"
#include <iostream>

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
				if(doc["result_id"].IsString())
					result_id = doc["result_id"].GetString();
				else
					std::cerr << "Error: Field \"result_id\" does not contain a string." << std::endl;

			if(doc.HasMember("from"))
				if(doc["from"].IsObject())
					from = std::make_shared<User>(tools::Tools::get_json_as_string(doc["from"]));
				else
					std::cerr << "Error: Field \"from\" does not contain a json object." << std::endl;

			if(doc.HasMember("location"))
				if(doc["location"].IsObject())
					location = std::make_shared<Location>(tools::Tools::get_json_as_string(doc["location"]));
				else
					std::cerr << "Error: Field \"location\" does not contain a json object." << std::endl;

			if(doc.HasMember("inline_message_id"))
				if(doc["inline_message_id"].IsString())
					inline_message_id = doc["inline_message_id"].GetString();
				else
					std::cerr << "Error: Field \"inline_message_id\" does not contain a string." << std::endl;

			if(doc.HasMember("query"))
				if(doc["query"].IsString())
					query = doc["query"].GetString();
				else
					std::cerr << "Error: Field \"query\" does not contain a string." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
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
