#include <rapidjson/document.h>
#include "tgbot/types/InlineQueryResultPhoto.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	InlineQueryResultPhoto::InlineQueryResultPhoto() : type(), id(), photo_url(), thumb_url(), photo_width(), photo_height(), title(), description(),
	caption(), parse_mode()
	{}

	InlineQueryResultPhoto::InlineQueryResultPhoto(const std::string &json)
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

			if(doc.HasMember("photo_url"))
				photo_url = doc["photo_url"].GetString();

			if(doc.HasMember("thumb_url"))
				thumb_url = doc["thumb_url"].GetString();

			if(doc.HasMember("photo_width"))
				photo_width = doc["photo_width"].GetInt();

			if(doc.HasMember("photo_height"))
				photo_height = doc["photo_height"].GetInt();

			if(doc.HasMember("title"))
				title = doc["title"].GetString();

			if(doc.HasMember("description"))
				description = doc["description"].GetString();

			if(doc.HasMember("caption"))
				caption = doc["caption"].GetString();

			if(doc.HasMember("parse_mode"))
				parse_mode = doc["parse_mode"].GetString();
		}
	}

	std::string InlineQueryResultPhoto::parse_to_json() const
	{
		std::string json = "{";

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//field photo_url
		json.append("\"photo_url\": \"" + photo_url + "\"");
		json.append(", ");

		//field thumb_url
		json.append("\"thumb_url\": \"" + thumb_url + "\"");
		json.append(", ");

		//field photo_width
		json.append("\"photo_width\": " + photo_width);
		json.append(", ");

		//field photo_height
		json.append("\"photo_height\": " + photo_height);
		json.append(", ");

		//field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//field description
		json.append("\"description\": \"" + description + "\"");
		json.append(", ");

		//field caption
		json.append("\"caption\": \"" + caption + "\"");
		json.append(", ");

		//field parse_mode
		json.append("\"parse_mode\": \"" + parse_mode + "\"");

		json.append("}");

		return json;
	}
}
