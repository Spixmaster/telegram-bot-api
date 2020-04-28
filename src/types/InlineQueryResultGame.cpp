#include "tgbot/types/InlineQueryResultGame.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	InlineQueryResultGame::InlineQueryResultGame() : type(), id(), game_short_name(), reply_markup()
	{}

	InlineQueryResultGame::InlineQueryResultGame(const std::string &json)
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
					std::cerr << Messages::field_does_not_contain_string("type") << std::endl;
			}

			if(doc.HasMember("id"))
			{
				if(doc["id"].IsString())
					id = doc["id"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("id") << std::endl;
			}

			if(doc.HasMember("game_short_name"))
			{
				if(doc["game_short_name"].IsString())
					game_short_name = doc["game_short_name"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("game_short_name") << std::endl;
			}

			if(doc.HasMember("reply_markup"))
			{
				if(doc["reply_markup"].IsObject())
					reply_markup = std::make_shared<InlineKeyboardMarkup>(tools::Tools::get_json_as_string(doc["reply_markup"]));
				else
					std::cerr << Messages::field_does_not_contain_json_obj("reply_markup") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string InlineQueryResultGame::parse_to_json() const noexcept
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
