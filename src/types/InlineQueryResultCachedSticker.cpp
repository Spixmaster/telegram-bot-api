#include "tgbot/types/InlineQueryResultCachedSticker.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	InlineQueryResultCachedSticker::InlineQueryResultCachedSticker() : type(), id(), sticker_file_id(), reply_markup(), input_message_content()
	{}

	InlineQueryResultCachedSticker::InlineQueryResultCachedSticker(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(Tools::is_json(json))
		{
			//assignments
			if(doc.HasMember("type"))
				type = doc["type"].GetString();

			if(doc.HasMember("id"))
				id = doc["id"].GetString();

			if(doc.HasMember("sticker_file_id"))
				sticker_file_id = doc["sticker_file_id"].GetString();

			if(doc.HasMember("reply_markup"))
				reply_markup = std::make_shared<InlineKeyboardMarkup>(SpecialTools::get_json_as_string(doc["reply_markup"]));
		}
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
