#include "tgbot/types/InlineQueryResultLocation.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	InlineQueryResultLocation::InlineQueryResultLocation() : type(), id(), latitude(), longitude(), title(), live_period(), reply_markup(), input_message_content()
	{}

	InlineQueryResultLocation::InlineQueryResultLocation(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("type"))
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					std::cerr << "Error: Field \"type\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"type\"." << std::endl;

			if(doc.HasMember("id"))
				if(doc["id"].IsString())
					id = doc["id"].GetString();
				else
					std::cerr << "Error: Field \"id\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"id\"." << std::endl;

			if(doc.HasMember("latitude"))
				latitude = doc["latitude"].GetFloat();

			if(doc.HasMember("longitude"))
				longitude = doc["longitude"].GetFloat();

			if(doc.HasMember("title"))
				title = doc["title"].GetString();
			if(doc.HasMember("title"))
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					std::cerr << "Error: Field \"title\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"title\"." << std::endl;

			if(doc.HasMember("live_period"))
				live_period = doc["live_period"].GetInt();

			if(doc.HasMember("reply_markup"))
				if(doc["reply_markup"].IsObject())
					reply_markup = std::make_shared<InlineKeyboardMarkup>(tools::Tools::get_json_as_string(doc["reply_markup"]));
				else
					std::cerr << "Error: Field \"reply_markup\" does not contain a json object." << std::endl;
			else
				std::cerr << "Error: There is no field \"reply_markup\"." << std::endl;
		}
	}

	std::string InlineQueryResultLocation::parse_to_json() const
	{
		std::string json = "{";

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//field latitude
		json.append("\"latitude\": " + std::to_string(latitude));
		json.append(", ");

		//field longitude
		json.append("\"longitude\": " + std::to_string(longitude));
		json.append(", ");

		//field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//field live_period
		json.append("\"live_period\": " + live_period);
		json.append(", ");

		//field reply_markup
		json.append("\"reply_markup\": " + reply_markup->parse_to_json());
		json.append(", ");

		//field input_message_content
		json.append("\"input_message_content\": " + input_message_content->parse_to_json());

		json.append("}");

		return json;
	}
}
