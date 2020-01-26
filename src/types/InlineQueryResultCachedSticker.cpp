#include "tgbot/types/InlineQueryResultCachedSticker.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	InlineQueryResultCachedSticker::InlineQueryResultCachedSticker() : type(), id(), sticker_file_id(), reply_markup(), input_message_content()
	{}

	InlineQueryResultCachedSticker::InlineQueryResultCachedSticker(const std::string &json)
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

			if(doc.HasMember("sticker_file_id"))
				if(doc["sticker_file_id"].IsString())
					sticker_file_id = doc["sticker_file_id"].GetString();
				else
					std::cerr << "Error: Field \"sticker_file_id\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"sticker_file_id\"." << std::endl;

			if(doc.HasMember("reply_markup"))
				reply_markup = std::make_shared<InlineKeyboardMarkup>(tools::Tools::get_json_as_string(doc["reply_markup"]));
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string InlineQueryResultCachedSticker::parse_to_json() const
	{
		std::string json = "{";

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//field sticker_file_id
		json.append("\"sticker_file_id\": \"" + sticker_file_id + "\"");
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
