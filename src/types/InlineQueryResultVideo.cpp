#include "tgbot/types/InlineQueryResultVideo.h"
#include "tools/Tools.h"

namespace tgbot
{
	InlineQueryResultVideo::InlineQueryResultVideo() : type(), id(), video_url(), mime_type(), thumb_url(), title(), caption(), parse_mode(),
	video_width(), video_height(), video_duration(), description(), reply_markup(), input_message_content()
	{}

	InlineQueryResultVideo::InlineQueryResultVideo(const std::string &json)
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

			if(doc.HasMember("video_url"))
				video_url = doc["video_url"].GetString();

			if(doc.HasMember("mime_type"))
				mime_type = doc["mime_type"].GetString();

			if(doc.HasMember("thumb_url"))
				thumb_url = doc["thumb_url"].GetString();

			if(doc.HasMember("title"))
				title = doc["title"].GetString();

			if(doc.HasMember("caption"))
				caption = doc["caption"].GetString();

			if(doc.HasMember("parse_mode"))
				parse_mode = doc["parse_mode"].GetString();

			if(doc.HasMember("video_width"))
				video_width = doc["video_width"].GetInt();

			if(doc.HasMember("video_height"))
				video_height = doc["video_height"].GetInt();

			if(doc.HasMember("video_duration"))
				video_duration = doc["video_duration"].GetInt();

			if(doc.HasMember("description"))
				description = doc["description"].GetString();

			if(doc.HasMember("reply_markup"))
				reply_markup = std::make_shared<InlineKeyboardMarkup>(tools::Tools::get_json_as_string(doc["reply_markup"]));
		}
	}

	std::string InlineQueryResultVideo::parse_to_json() const
	{
		std::string json = "{";

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//field video_url
		json.append("\"video_url\": \"" + video_url + "\"");
		json.append(", ");

		//field mime_type
		json.append("\"mime_type\": \"" + mime_type + "\"");
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

		//field video_width
		json.append("\"video_width\": " + video_width);
		json.append(", ");

		//field video_height
		json.append("\"video_height\": " + video_height);
		json.append(", ");

		//field video_duration
		json.append("\"video_duration\": " + video_duration);
		json.append(", ");

		//field description
		json.append("\"description\": \"" + description + "\"");
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
