#include "tgbot/types/InlineQueryResultVideo.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

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
			//Assignments
			if(doc.HasMember("type"))
			{
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("type"));
			}

			if(doc.HasMember("id"))
			{
				if(doc["id"].IsString())
					id = doc["id"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("id"));
			}

			if(doc.HasMember("video_url"))
			{
				if(doc["video_url"].IsString())
					video_url = doc["video_url"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("video_url"));
			}

			if(doc.HasMember("mime_type"))
			{
				if(doc["mime_type"].IsString())
					mime_type = doc["mime_type"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("mime_type"));
			}

			if(doc.HasMember("thumb_url"))
			{
				if(doc["thumb_url"].IsString())
					thumb_url = doc["thumb_url"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("thumb_url"));
			}

			if(doc.HasMember("title"))
			{
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("title"));
			}

			if(doc.HasMember("caption"))
			{
				if(doc["caption"].IsString())
					caption = doc["caption"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("caption"));
			}

			if(doc.HasMember("parse_mode"))
			{
				if(doc["parse_mode"].IsString())
					parse_mode = doc["parse_mode"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("parse_mode"));
			}

			if(doc.HasMember("video_width"))
			{
				if(doc["video_width"].IsInt())
					video_width = doc["video_width"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("video_width"));
			}

			if(doc.HasMember("video_height"))
			{
				if(doc["video_height"].IsInt())
					video_height = doc["video_height"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("video_height"));
			}

			if(doc.HasMember("video_duration"))
			{
				if(doc["video_duration"].IsInt())
					video_duration = doc["video_duration"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("video_duration"));
			}

			if(doc.HasMember("description"))
			{
				if(doc["description"].IsString())
					description = doc["description"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("description"));
			}

			if(doc.HasMember("reply_markup"))
			{
				if(doc["reply_markup"].IsObject())
					reply_markup = std::make_shared<InlineKeyboardMarkup>(tools::Tools::get_json_as_string(doc["reply_markup"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("reply_markup"));
			}

			if(doc.HasMember("input_message_content"))
			{
				if(doc["input_message_content"].IsObject())
					input_message_content = std::make_shared<InputMessageContent>(tools::Tools::get_json_as_string(doc["input_message_content"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("input_message_content"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string InlineQueryResultVideo::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//Field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//Field video_url
		json.append("\"video_url\": \"" + video_url + "\"");
		json.append(", ");

		//Field mime_type
		json.append("\"mime_type\": \"" + mime_type + "\"");
		json.append(", ");

		//Field thumb_url
		json.append("\"thumb_url\": \"" + thumb_url + "\"");
		json.append(", ");

		//Field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//Field caption
		json.append("\"caption\": \"" + caption + "\"");
		json.append(", ");

		//Field parse_mode
		json.append("\"parse_mode\": \"" + parse_mode + "\"");
		json.append(", ");

		//Field video_width
		json.append("\"video_width\": " + video_width);
		json.append(", ");

		//Field video_height
		json.append("\"video_height\": " + video_height);
		json.append(", ");

		//Field video_duration
		json.append("\"video_duration\": " + video_duration);
		json.append(", ");

		//Field description
		json.append("\"description\": \"" + description + "\"");
		json.append(", ");

		//Field reply_markup
		json.append("\"reply_markup\": " + reply_markup->parse_to_json());
		json.append(", ");

		//Field input_message_content
		json.append("\"input_message_content\": " + input_message_content->parse_to_json());

		json.append("}");

		return json;
	}
}
