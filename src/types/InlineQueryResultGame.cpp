#include "tgbot/types/InlineQueryResultGame.h"

namespace tgbot
{
	InlineQueryResultGame::InlineQueryResultGame() : type(), id(), game_short_name(), reply_markup()
	{}

	InlineQueryResultGame::InlineQueryResultGame(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("type"))
			type = doc["type"].GetString();

		if(doc.HasMember("id"))
			id = doc["id"].GetString();

		if(doc.HasMember("game_short_name"))
			game_short_name = doc["game_short_name"].GetString();

		if(doc.HasMember("reply_markup"))
			reply_markup = std::make_shared<InlineKeyboardMarkup>(special_tools::get_json_obj_as_string(doc["reply_markup"]));
	}
	std::string InlineQueryResultGame::parse_to_json() const
	{
		std::string json = "{";

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//field game_short_name
		json.append("\"game_short_name\": \"" + game_short_name + "\"");
		json.append(", ");

		//field reply_markup
		json.append("\"reply_markup\": " + reply_markup->parse_to_json());

		json.append("}");

		return json;
	}
}
