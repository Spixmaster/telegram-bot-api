#include "tgbot/types/InlineQuery.h"
#include "tools/Tools.h"
#include <iostream>

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
			//assignments
			if(doc.HasMember("id"))
				if(doc["id"].IsString())
					id = doc["id"].GetString();
				else
					std::cerr << "Error: Field \"id\" does not contain a string." << std::endl;

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

			if(doc.HasMember("query"))
				if(doc["query"].IsString())
					query = doc["query"].GetString();
				else
					std::cerr << "Error: Field \"query\" does not contain a string." << std::endl;

			if(doc.HasMember("offset"))
				if(doc["offset"].IsString())
					offset = doc["offset"].GetString();
				else
					std::cerr << "Error: Field \"offset\" does not contain a string." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string InlineQuery::parse_to_json() const
	{
		std::string json = "{";

		//field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//field from
		json.append("\"from\": " + from->parse_to_json());
		json.append(", ");

		//field location
		json.append("\"location\": " + location->parse_to_json());
		json.append(", ");

		//field query
		json.append("\"query\": \"" + query + "\"");
		json.append(", ");

		//field offset
		json.append("\"offset\": \"" + offset + "\"");

		json.append("}");

		return json;
	}
}
