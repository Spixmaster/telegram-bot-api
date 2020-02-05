#include "tgbot/types/InlineQueryResultVideo.h"
#include "tools/Tools.h"
#include <iostream>

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

			if(doc.HasMember("video_url"))
			{
				if(doc["video_url"].IsString())
					video_url = doc["video_url"].GetString();
				else
					std::cerr << "Error: Field \"video_url\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("mime_type"))
			{
				if(doc["mime_type"].IsString())
					mime_type = doc["mime_type"].GetString();
				else
					std::cerr << "Error: Field \"mime_type\" does not contain a string." << std::endl;
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

			if(doc.HasMember("video_width"))
			{
				if(doc["video_width"].IsInt())
					video_width = doc["video_width"].GetInt();
				else
					std::cerr << "Error: Field \"video_width\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("video_height"))
			{
				if(doc["video_height"].IsInt())
					video_height = doc["video_height"].GetInt();
				else
					std::cerr << "Error: Field \"video_height\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("video_duration"))
			{
				if(doc["video_duration"].IsInt())
					video_duration = doc["video_duration"].GetInt();
				else
					std::cerr << "Error: Field \"video_duration\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("description"))
			{
				if(doc["description"].IsString())
					description = doc["description"].GetString();
				else
					std::cerr << "Error: Field \"description\" does not contain a string." << std::endl;
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

	std::string InlineQueryResultVideo::parse_to_json() const noexcept
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
