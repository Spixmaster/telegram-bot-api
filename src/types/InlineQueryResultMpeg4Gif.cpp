#include "tgbot/types/InlineQueryResultMpeg4Gif.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	InlineQueryResultMpeg4Gif::InlineQueryResultMpeg4Gif() : type(), id(), mpeg4_url(), mpeg4_width(), mpeg4_height(), mpeg4_duration(), thumb_url(), title(),
	caption(), parse_mode(), reply_markup(), input_message_content()
	{}

	InlineQueryResultMpeg4Gif::InlineQueryResultMpeg4Gif(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("type"))
			{
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					std::cerr << "Error: Field \"type\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("id"))
			{
				if(doc["id"].IsString())
					id = doc["id"].GetString();
				else
					std::cerr << "Error: Field \"id\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("mpeg4_url"))
			{
				if(doc["mpeg4_url"].IsString())
					mpeg4_url = doc["mpeg4_url"].GetString();
				else
					std::cerr << "Error: Field \"mpeg4_url\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("mpeg4_width"))
			{
				if(doc["mpeg4_width"].IsInt())
					mpeg4_width = doc["mpeg4_width"].GetInt();
				else
					std::cerr << "Error: Field \"mpeg4_width\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("mpeg4_height"))
			{
				if(doc["mpeg4_height"].IsInt())
					mpeg4_height = doc["mpeg4_height"].GetInt();
				else
					std::cerr << "Error: Field \"mpeg4_height\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("mpeg4_duration"))
			{
				if(doc["mpeg4_duration"].IsInt())
					mpeg4_duration = doc["mpeg4_duration"].GetInt();
				else
					std::cerr << "Error: Field \"mpeg4_duration\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("thumb_url"))
			{
				if(doc["thumb_url"].IsString())
					thumb_url = doc["thumb_url"].GetString();
				else
					std::cerr << "Error: Field \"thumb_url\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("title"))
			{
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					std::cerr << "Error: Field \"title\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("caption"))
			{
				if(doc["caption"].IsString())
					caption = doc["caption"].GetString();
				else
					std::cerr << "Error: Field \"caption\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("parse_mode"))
			{
				if(doc["parse_mode"].IsString())
					parse_mode = doc["parse_mode"].GetString();
				else
					std::cerr << "Error: Field \"parse_mode\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("reply_markup"))
			{
				if(doc["reply_markup"].IsObject())
					reply_markup = std::make_shared<InlineKeyboardMarkup>(tools::Tools::get_json_as_string(doc["reply_markup"]));
				else
					std::cerr << "Error: Field \"reply_markup\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("input_message_content"))
			{
				if(doc["input_message_content"].IsObject())
					input_message_content = std::make_shared<InputMessageContent>(tools::Tools::get_json_as_string(doc["input_message_content"]));
				else
					std::cerr << "Error: Field \"input_message_content\" does not contain a json object." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
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
