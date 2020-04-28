#include "tgbot/types/ChosenInlineResult.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

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
			{
				if(doc["result_id"].IsString())
					result_id = doc["result_id"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("result_id") << std::endl;
			}

			if(doc.HasMember("from"))
			{
				if(doc["from"].IsObject())
					from = std::make_shared<User>(tools::Tools::get_json_as_string(doc["from"]));
				else
					std::cerr << Messages::field_does_not_contain_json_obj("from") << std::endl;
			}

			if(doc.HasMember("location"))
			{
				if(doc["location"].IsObject())
					location = std::make_shared<Location>(tools::Tools::get_json_as_string(doc["location"]));
				else
					std::cerr << Messages::field_does_not_contain_json_obj("location") << std::endl;
			}

			if(doc.HasMember("inline_message_id"))
			{
				if(doc["inline_message_id"].IsString())
					inline_message_id = doc["inline_message_id"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("inline_message_id") << std::endl;
			}

			if(doc.HasMember("query"))
			{
				if(doc["query"].IsString())
					query = doc["query"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("query") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string ChosenInlineResult::parse_to_json() const noexcept
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
