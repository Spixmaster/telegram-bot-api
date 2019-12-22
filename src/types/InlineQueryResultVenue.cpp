#include "tgbot/types/InlineQueryResultVenue.h"
#include "tools/Tools.h"

namespace tgbot
{
	InlineQueryResultVenue::InlineQueryResultVenue() : type(), id(), latitude(), longitude(), title(), address(), foursquare_id(), foursquare_type(),
	reply_markup(), input_message_content(), thumb_url(), thumb_width(), thumb_height()
	{}

	InlineQueryResultVenue::InlineQueryResultVenue(const std::string &json)
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

			if(doc.HasMember("address"))
				address = doc["address"].GetString();

			if(doc.HasMember("foursquare_id"))
				foursquare_id = doc["foursquare_id"].GetString();

			if(doc.HasMember("foursquare_type"))
				foursquare_type = doc["foursquare_type"].GetString();

			if(doc.HasMember("reply_markup"))
				reply_markup = std::make_shared<InlineKeyboardMarkup>(tools::Tools::get_json_as_string(doc["reply_markup"]));

			if(doc.HasMember("thumb_url"))
				thumb_url = doc["thumb_url"].GetString();

			if(doc.HasMember("thumb_width"))
				thumb_width = doc["thumb_width"].GetInt();

			if(doc.HasMember("thumb_height"))
				thumb_height = doc["thumb_height"].GetInt();
		}
	}

	std::string InlineQueryResultVenue::parse_to_json() const
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

		//field address
		json.append("\"address\": \"" + address + "\"");
		json.append(", ");

		//field foursquare_id
		json.append("\"foursquare_id\": \"" + foursquare_id + "\"");
		json.append(", ");

		//field foursquare_type
		json.append("\"foursquare_type\": \"" + foursquare_type + "\"");
		json.append(", ");

		//field reply_markup
		json.append("\"reply_markup\": " + reply_markup->parse_to_json());
		json.append(", ");

		//field input_message_content
		json.append("\"input_message_content\": " + input_message_content->parse_to_json());
		json.append(", ");

		//field thumb_url
		json.append("\"thumb_url\": \"" + thumb_url + "\"");
		json.append(", ");

		//field thumb_width
		json.append("\"thumb_width\": " + thumb_width);
		json.append(", ");

		//field thumb_height
		json.append("\"thumb_height\": " + thumb_height);

		json.append("}");

		return json;
	}
}
