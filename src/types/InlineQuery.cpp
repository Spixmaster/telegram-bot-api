#include "tgbot/types/InlineQuery.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	InlineQuery::InlineQuery() : id(), from(), location(), query(), offset()
	{}

	InlineQuery::InlineQuery(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(Tools::is_json(json))
		{
			//assignments
			if(doc.HasMember("id"))
				id = doc["id"].GetString();

			if(doc.HasMember("from"))
				from = std::make_shared<User>(SpecialTools::get_json_as_string(doc["from"]));

			if(doc.HasMember("location"))
				location = std::make_shared<Location>(SpecialTools::get_json_as_string(doc["location"]));

			if(doc.HasMember("query"))
				query = doc["query"].GetString();

			if(doc.HasMember("offset"))
				offset = doc["offset"].GetString();
		}
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
