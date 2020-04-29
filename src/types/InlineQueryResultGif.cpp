#include "tgbot/types/InlineQueryResultGif.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	InlineQueryResultGif::InlineQueryResultGif() : type(), id(), gif_url(), gif_width(), gif_height(), gif_duration(), thumb_url(), title(),
	caption(), parse_mode(), reply_markup(), input_message_content()
	{}

	InlineQueryResultGif::InlineQueryResultGif(const std::string &json)
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

			if(doc.HasMember("gif_url"))
			{
				if(doc["gif_url"].IsString())
					gif_url = doc["gif_url"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("gif_url"));
			}

			if(doc.HasMember("gif_width"))
			{
				if(doc["gif_width"].IsInt())
					gif_width = doc["gif_width"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("gif_width"));
			}

			if(doc.HasMember("gif_height"))
			{
				if(doc["gif_height"].IsInt())
					gif_height = doc["gif_height"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("gif_height"));
			}

			if(doc.HasMember("gif_duration"))
			{
				if(doc["gif_duration"].IsInt())
					gif_duration = doc["gif_duration"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("gif_duration"));
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

	std::string InlineQueryResultGif::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//Field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//Field gif_url
		json.append("\"gif_url\": \"" + gif_url + "\"");
		json.append(", ");

		//Field gif_width
		json.append("\"gif_width\": " + gif_width);
		json.append(", ");

		//Field gif_height
		json.append("\"gif_height\": " + gif_height);
		json.append(", ");

		//Field gif_duration
		json.append("\"gif_duration\": " + gif_duration);
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

		//Field reply_markup
		json.append("\"reply_markup\": " + reply_markup->parse_to_json());
		json.append(", ");

		//Field input_message_content
		json.append("\"input_message_content\": " + input_message_content->parse_to_json());

		json.append("}");

		return json;
	}
}
