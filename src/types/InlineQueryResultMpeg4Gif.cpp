#include "tgbot/types/InlineQueryResultMpeg4Gif.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	InlineQueryResultMpeg4Gif::InlineQueryResultMpeg4Gif() : type(), id(), mpeg4_url(), mpeg4_width(), mpeg4_height(), mpeg4_duration(), thumb_url(), thumb_mime_type(),
			title(), caption(), parse_mode(), reply_markup(), input_message_content()
	{}

	InlineQueryResultMpeg4Gif::InlineQueryResultMpeg4Gif(const std::string &json)
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

			if(doc.HasMember("mpeg4_url"))
			{
				if(doc["mpeg4_url"].IsString())
					mpeg4_url = doc["mpeg4_url"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("mpeg4_url"));
			}

			if(doc.HasMember("mpeg4_width"))
			{
				if(doc["mpeg4_width"].IsInt())
					mpeg4_width = doc["mpeg4_width"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("mpeg4_width"));
			}

			if(doc.HasMember("mpeg4_height"))
			{
				if(doc["mpeg4_height"].IsInt())
					mpeg4_height = doc["mpeg4_height"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("mpeg4_height"));
			}

			if(doc.HasMember("mpeg4_duration"))
			{
				if(doc["mpeg4_duration"].IsInt())
					mpeg4_duration = doc["mpeg4_duration"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("mpeg4_duration"));
			}

			if(doc.HasMember("thumb_url"))
			{
				if(doc["thumb_url"].IsString())
					thumb_url = doc["thumb_url"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("thumb_url"));
			}

			if(doc.HasMember("thumb_mime_type"))
			{
				if(doc["thumb_mime_type"].IsString())
					thumb_url = doc["thumb_mime_type"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("thumb_mime_type"));
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

	std::string InlineQueryResultMpeg4Gif::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//Field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//Field mpeg4_url
		json.append("\"mpeg4_url\": \"" + mpeg4_url + "\"");
		json.append(", ");

		//Field mpeg4_width
		json.append("\"mpeg4_width\": \"" + mpeg4_width);
		json.append(", ");

		//Field mpeg4_height
		json.append("\"mpeg4_height\": \"" + mpeg4_height);
		json.append(", ");

		//Field mpeg4_duration
		json.append("\"mpeg4_duration\": \"" + mpeg4_duration);
		json.append(", ");

		//Field thumb_url
		json.append("\"thumb_url\": \"" + thumb_url + "\"");
		json.append(", ");

		//Field thumb_mime_type
		json.append("\"thumb_mime_type\": \"" + thumb_mime_type + "\"");
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

		//Field reply_markup
		json.append("\"reply_markup\": " + reply_markup->parse_to_json());
		json.append(", ");

		//Field input_message_content
		json.append("\"input_message_content\": " + input_message_content->parse_to_json());

		json.append("}");
		return json;
	}
}
