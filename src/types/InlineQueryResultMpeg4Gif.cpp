#include "tgbot/types/InlineQueryResultMpeg4Gif.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	InlineQueryResultMpeg4Gif::InlineQueryResultMpeg4Gif() : id(), mpeg4_url(), mpeg4_width(), mpeg4_height(), mpeg4_duration(), thumb_url(), title(),
	caption(), parse_mode(), reply_markup(), input_message_content()
	{}

	InlineQueryResultMpeg4Gif::InlineQueryResultMpeg4Gif(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("id"))
			{
				if(doc["id"].IsString())
					id = doc["id"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("id") << std::endl;
			}

			if(doc.HasMember("mpeg4_url"))
			{
				if(doc["mpeg4_url"].IsString())
					mpeg4_url = doc["mpeg4_url"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("mpeg4_url") << std::endl;
			}

			if(doc.HasMember("mpeg4_width"))
			{
				if(doc["mpeg4_width"].IsInt())
					mpeg4_width = doc["mpeg4_width"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("mpeg4_width") << std::endl;
			}

			if(doc.HasMember("mpeg4_height"))
			{
				if(doc["mpeg4_height"].IsInt())
					mpeg4_height = doc["mpeg4_height"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("mpeg4_height") << std::endl;
			}

			if(doc.HasMember("mpeg4_duration"))
			{
				if(doc["mpeg4_duration"].IsInt())
					mpeg4_duration = doc["mpeg4_duration"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("mpeg4_duration") << std::endl;
			}

			if(doc.HasMember("thumb_url"))
			{
				if(doc["thumb_url"].IsString())
					thumb_url = doc["thumb_url"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("thumb_url") << std::endl;
			}

			if(doc.HasMember("title"))
			{
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("title") << std::endl;
			}

			if(doc.HasMember("caption"))
			{
				if(doc["caption"].IsString())
					caption = doc["caption"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("caption") << std::endl;
			}

			if(doc.HasMember("parse_mode"))
			{
				if(doc["parse_mode"].IsString())
					parse_mode = doc["parse_mode"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("parse_mode") << std::endl;
			}

			if(doc.HasMember("reply_markup"))
			{
				if(doc["reply_markup"].IsObject())
					reply_markup = std::make_shared<InlineKeyboardMarkup>(tools::Tools::get_json_as_string(doc["reply_markup"]));
				else
					std::cerr << Messages::field_does_not_contain_json_obj("reply_markup") << std::endl;
			}

			if(doc.HasMember("input_message_content"))
			{
				if(doc["input_message_content"].IsObject())
					input_message_content = std::make_shared<InputMessageContent>(tools::Tools::get_json_as_string(doc["input_message_content"]));
				else
					std::cerr << Messages::field_does_not_contain_json_obj("input_message_content") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string InlineQueryResultMpeg4Gif::parse_to_json() const noexcept
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
