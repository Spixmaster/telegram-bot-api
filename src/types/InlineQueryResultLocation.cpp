#include "tgbot/types/InlineQueryResultLocation.h"
#include "tools/Tools.h"

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
				type = doc["type"].GetString();

			if(doc.HasMember("id"))
				id = doc["id"].GetString();

			if(doc.HasMember("latitude"))
				latitude = doc["latitude"].GetFloat();

			if(doc.HasMember("longitude"))
				longitude = doc["longitude"].GetFloat();

			if(doc.HasMember("title"))
				title = doc["title"].GetString();

			if(doc.HasMember("live_period"))
				live_period = doc["live_period"].GetInt();

			if(doc.HasMember("reply_markup"))
				reply_markup = std::make_shared<InlineKeyboardMarkup>(tools::Tools::get_json_as_string(doc["reply_markup"]));
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
