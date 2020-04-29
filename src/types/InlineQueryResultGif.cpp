#include "tgbot/types/InlineQueryResultGif.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	InlineQueryResultGif::InlineQueryResultGif() : id(), gif_url(), gif_width(), gif_height(), gif_duration(), thumb_url(), title(),
	caption(), parse_mode(), reply_markup(), input_message_content()
	{}

	InlineQueryResultGif::InlineQueryResultGif(const std::string &json)
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

			if(doc.HasMember("gif_url"))
			{
				if(doc["gif_url"].IsString())
					gif_url = doc["gif_url"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("gif_url") << std::endl;
			}

			if(doc.HasMember("gif_width"))
			{
				if(doc["gif_width"].IsInt())
					gif_width = doc["gif_width"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("gif_width") << std::endl;
			}

			if(doc.HasMember("gif_height"))
			{
				if(doc["gif_height"].IsInt())
					gif_height = doc["gif_height"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("gif_height") << std::endl;
			}

			if(doc.HasMember("gif_duration"))
			{
				if(doc["gif_duration"].IsInt())
					gif_duration = doc["gif_duration"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("gif_duration") << std::endl;
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

	std::string InlineQueryResultGif::parse_to_json() const noexcept
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
