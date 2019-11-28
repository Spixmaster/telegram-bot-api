#include "tgbot/types/InlineQueryResultCachedPhoto.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	InlineQueryResultCachedPhoto::InlineQueryResultCachedPhoto() : type(), id(), photo_file_id(), title(), description(), caption(), parse_mode(),
	reply_markup(), input_message_content()
	{}

	InlineQueryResultCachedPhoto::InlineQueryResultCachedPhoto(const std::string &json)
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

			if(doc.HasMember("mpeg4_file_id"))
				photo_file_id = doc["mpeg4_file_id"].GetString();

			if(doc.HasMember("title"))
				title = doc["title"].GetString();

			if(doc.HasMember("description"))
				description = doc["description"].GetString();

			if(doc.HasMember("caption"))
				caption = doc["caption"].GetString();

			if(doc.HasMember("parse_mode"))
				parse_mode = doc["parse_mode"].GetString();

			if(doc.HasMember("reply_markup"))
				reply_markup = std::make_shared<InlineKeyboardMarkup>(SpecialTools::get_json_as_string(doc["reply_markup"]));
		}
	}

	std::string InlineQueryResultCachedPhoto::parse_to_json() const
	{
		std::string json = "{";

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//field photo_file_id
		json.append("\"photo_file_id\": \"" + photo_file_id + "\"");
		json.append(", ");

		//field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//field caption
		json.append("\"caption\": \"" + caption + "\"");
		json.append(", ");

		//field parse_mode
		json.append("\"parse_mode\": \"" + parse_mode + "\"");
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
