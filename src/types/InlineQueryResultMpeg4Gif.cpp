#include "tgbot/types/InlineQueryResultMpeg4Gif.h"

namespace tgbot
{
	InlineQueryResultMpeg4Gif::InlineQueryResultMpeg4Gif() : type(), id(), mpeg4_url(), mpeg4_width(), mpeg4_height(), mpeg4_duration(), thumb_url(), title(),
	caption(), parse_mode(), reply_markup(), input_message_content()
	{}

	InlineQueryResultMpeg4Gif::InlineQueryResultMpeg4Gif(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("type"))
			type = doc["type"].GetString();

		if(doc.HasMember("id"))
			id = doc["id"].GetString();

		if(doc.HasMember("mpeg4_url"))
			mpeg4_url = doc["mpeg4_url"].GetString();

		if(doc.HasMember("mpeg4_width"))
			mpeg4_width = doc["mpeg4_width"].GetInt();

		if(doc.HasMember("mpeg4_height"))
			mpeg4_height = doc["mpeg4_height"].GetInt();

		if(doc.HasMember("mpeg4_duration"))
			mpeg4_duration = doc["mpeg4_duration"].GetInt();

		if(doc.HasMember("thumb_url"))
			thumb_url = doc["thumb_url"].GetString();

		if(doc.HasMember("title"))
			title = doc["title"].GetString();

		if(doc.HasMember("caption"))
			caption = doc["caption"].GetString();

		if(doc.HasMember("parse_mode"))
			parse_mode = doc["parse_mode"].GetString();

		if(doc.HasMember("reply_markup"))
			reply_markup = std::make_shared<InlineKeyboardMarkup>(special_tools::get_json_obj_as_string(doc["reply_markup"]));
	}

	std::string InlineQueryResultMpeg4Gif::parse_to_json() const
	{
		std::string json = "{";

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//field mpeg4_url
		json.append("\"mpeg4_url\": \"" + mpeg4_url + "\"");
		json.append(", ");

		//field mpeg4_width
		json.append("\"mpeg4_width\": \"" + mpeg4_width);
		json.append(", ");

		//field mpeg4_height
		json.append("\"mpeg4_height\": \"" + mpeg4_height);
		json.append(", ");

		//field mpeg4_duration
		json.append("\"mpeg4_duration\": \"" + mpeg4_duration);
		json.append(", ");

		//field thumb_url
		json.append("\"thumb_url\": \"" + thumb_url + "\"");
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
