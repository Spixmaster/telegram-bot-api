#include "tgbot/types/CallbackQuery.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	CallbackQuery::CallbackQuery() : id(), from(), message(), inline_message_id(), chat_instance(), data(), game_short_name()
	{}

	CallbackQuery::CallbackQuery(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(Tools::is_json(json))
		{
			//assignments
			if(doc.HasMember("id"))
				id = doc["id"].GetString();

			if(doc.HasMember("from"))
				from = std::make_shared<User>(SpecialTools::get_json_as_string(doc["from"]));

			if(doc.HasMember("message"))
				message = std::make_shared<Message>(SpecialTools::get_json_as_string(doc["message"]));

			if(doc.HasMember("inline_message_id"))
				inline_message_id = doc["inline_message_id"].GetString();

			if(doc.HasMember("chat_instance"))
				chat_instance = doc["chat_instance"].GetString();

			if(doc.HasMember("data"))
				data = doc["data"].GetString();

			if(doc.HasMember("game_short_name"))
				game_short_name = doc["game_short_name"].GetString();
		}
	}

	std::string CallbackQuery::parse_to_json() const
	{
		std::string json = "{";

		//field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//field from
		json.append("\"from\": " + from->parse_to_json());
		json.append(", ");

		//field message
		json.append("\"message\": " + message->parse_to_json());
		json.append(", ");

		//field inline_message_id
		json.append("\"inline_message_id\": \"" + inline_message_id + "\"");
		json.append(", ");

		//field chat_instance
		json.append("\"chat_instance\": \"" + chat_instance + "\"");
		json.append(", ");

		//field data
		json.append("\"data\": \"" + data + "\"");
		json.append(", ");

		//field game_short_name
		json.append("\"game_short_name\": \"" + game_short_name + "\"");

		json.append("}");

		return json;
	}
}
