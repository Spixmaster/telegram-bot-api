#include "tgbot/types/InlineQuery.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	InlineQuery::InlineQuery() : id(), from(), location(), query(), offset()
	{}

	InlineQuery::InlineQuery(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//Assignments
			if(doc.HasMember("id"))
			{
				if(doc["id"].IsString())
					id = doc["id"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("id"));
			}

			if(doc.HasMember("from"))
			{
				if(doc["from"].IsObject())
					from = std::make_shared<User>(tools::Tools::get_json_as_string(doc["from"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("from"));
			}

			if(doc.HasMember("location"))
			{
				if(doc["location"].IsObject())
					location = std::make_shared<Location>(tools::Tools::get_json_as_string(doc["location"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("location"));
			}

			if(doc.HasMember("query"))
			{
				if(doc["query"].IsString())
					query = doc["query"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("query"));
			}

			if(doc.HasMember("offset"))
			{
				if(doc["offset"].IsString())
					offset = doc["offset"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("offset"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string InlineQuery::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//Field from
		json.append("\"from\": " + from->parse_to_json());
		json.append(", ");

		//Field location
		json.append("\"location\": " + location->parse_to_json());
		json.append(", ");

		//Field query
		json.append("\"query\": \"" + query + "\"");
		json.append(", ");

		//Field offset
		json.append("\"offset\": \"" + offset + "\"");

		json.append("}");

		return json;
	}
}
