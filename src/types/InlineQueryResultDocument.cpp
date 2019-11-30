#include "tgbot/types/InlineQueryResultDocument.h"
#include "tools/Tools.h"

namespace tgbot
{
	InlineQueryResultDocument::InlineQueryResultDocument() : type(), id(), title(), caption(), parse_mode(), document_url(), mime_type(), description(),
	reply_markup(), input_message_content(), thumb_url(), thumb_width(), thumb_height()
	{}

	InlineQueryResultDocument::InlineQueryResultDocument(const std::string &json)
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

			if(doc.HasMember("title"))
				title = doc["title"].GetString();

			if(doc.HasMember("caption"))
				caption = doc["caption"].GetString();

			if(doc.HasMember("parse_mode"))
				parse_mode = doc["parse_mode"].GetString();

			if(doc.HasMember("document_url"))
				document_url = doc["document_url"].GetString();

			if(doc.HasMember("mime_type"))
				mime_type = doc["mime_type"].GetString();

			if(doc.HasMember("mime_type"))
				description = doc["mime_type"].GetString();

			if(doc.HasMember("reply_markup"))
				reply_markup = std::make_shared<InlineKeyboardMarkup>(SpecialTools::get_json_as_string(doc["reply_markup"]));

			if(doc.HasMember("thumb_url"))
				thumb_url = doc["thumb_url"].GetString();

			if(doc.HasMember("thumb_width"))
				thumb_width = doc["thumb_width"].GetInt();

			if(doc.HasMember("thumb_height"))
				thumb_height = doc["thumb_height"].GetInt();
		}
	}

	std::string InlineQueryResultDocument::parse_to_json() const
	{
		std::string json = "{";

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field id
		json.append("\"id\": \"" + id + "\"");
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

		//field document_url
		json.append("\"document_url\": \"" + document_url + "\"");
		json.append(", ");

		//field mime_type
		json.append("\"mime_type\": \"" + mime_type + "\"");
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
		json.append("\"thumb_url\": " + thumb_width);
		json.append(", ");

		//field thumb_height
		json.append("\"thumb_height\": " + thumb_height);

		json.append("}");

		return json;
	}
}
