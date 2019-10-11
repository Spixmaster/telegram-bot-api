#include "tgbot/types/InlineQueryResultGif.h"

namespace tgbot
{
	InlineQueryResultGif::InlineQueryResultGif() : type(), id(), gif_url(), gif_width(), gif_height(), gif_duration(), thumb_url(), title(),
	caption(), parse_mode(), reply_markup(), input_message_content()
	{}

	InlineQueryResultGif::InlineQueryResultGif(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("type"))
			type = doc["type"].GetString();

		if(doc.HasMember("id"))
			id = doc["id"].GetString();

		if(doc.HasMember("gif_url"))
			gif_url = doc["gif_url"].GetString();

		if(doc.HasMember("caption"))
			gif_width = doc["caption"].GetInt();

		if(doc.HasMember("parse_mode"))
			gif_height = doc["parse_mode"].GetInt();

		if(doc.HasMember("document_url"))
			gif_duration = doc["document_url"].GetInt();

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

	std::string InlineQueryResultGif::parse_to_json() const
	{
		std::string json = "{";

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//field gif_url
		json.append("\"gif_url\": \"" + gif_url + "\"");
		json.append(", ");

		//field gif_width
		json.append("\"gif_width\": " + gif_width);
		json.append(", ");

		//field gif_height
		json.append("\"gif_height\": " + gif_height);
		json.append(", ");

		//field gif_duration
		json.append("\"gif_duration\": " + gif_duration);
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
