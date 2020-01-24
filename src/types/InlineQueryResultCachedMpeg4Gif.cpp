#include "tgbot/types/InlineQueryResultCachedMpeg4Gif.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	InlineQueryResultCachedMpeg4Gif::InlineQueryResultCachedMpeg4Gif() : type(), id(), mpeg4_file_id(), title(), caption(), parse_mode(),
	reply_markup(), input_message_content()
	{}

	InlineQueryResultCachedMpeg4Gif::InlineQueryResultCachedMpeg4Gif(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("type"))
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					std::cerr << "Error: Field \"type\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"type\"." << std::endl;

			if(doc.HasMember("id"))
				if(doc["id"].IsString())
					id = doc["id"].GetString();
				else
					std::cerr << "Error: Field \"id\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"id\"." << std::endl;

			if(doc.HasMember("mpeg4_file_id"))
				if(doc["mpeg4_file_id"].IsString())
					mpeg4_file_id = doc["mpeg4_file_id"].GetString();
				else
					std::cerr << "Error: Field \"mpeg4_file_id\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"mpeg4_file_id\"." << std::endl;

			if(doc.HasMember("title"))
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					std::cerr << "Error: Field \"title\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"title\"." << std::endl;

			if(doc.HasMember("caption"))
				if(doc["caption"].IsString())
					caption = doc["caption"].GetString();
				else
					std::cerr << "Error: Field \"caption\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"caption\"." << std::endl;

			if(doc.HasMember("parse_mode"))
				if(doc["parse_mode"].IsString())
					parse_mode = doc["parse_mode"].GetString();
				else
					std::cerr << "Error: Field \"parse_mode\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"parse_mode\"." << std::endl;

			if(doc.HasMember("reply_markup"))
				if(doc["reply_markup"].IsObject())
					reply_markup = std::make_shared<InlineKeyboardMarkup>(tools::Tools::get_json_as_string(doc["reply_markup"]));
				else
					std::cerr << "Error: Field \"reply_markup\" does not contain a json object." << std::endl;
			else
				std::cerr << "Error: There is no field \"reply_markup\"." << std::endl;
		}
	}

	std::string InlineQueryResultCachedMpeg4Gif::parse_to_json() const
	{
		std::string json = "{";

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//field mpeg4_file_id
		json.append("\"mpeg4_file_id\": \"" + mpeg4_file_id + "\"");
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
