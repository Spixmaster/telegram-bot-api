#include "tgbot/types/CallbackQuery.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	CallbackQuery::CallbackQuery() : id(), from(), message(), inline_message_id(), chat_instance(), data(), game_short_name()
	{}

	CallbackQuery::CallbackQuery(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("id"))
				if(doc["id"].IsString())
					id = doc["id"].GetString();
				else
					std::cerr << "Error: Field \"id\" does not contain a string." << std::endl;

			if(doc.HasMember("from"))
				if(doc["from"].IsObject())
					from = std::make_shared<User>(tools::Tools::get_json_as_string(doc["from"]));
				else
					std::cerr << "Error: Field \"from\" does not contain a json object." << std::endl;

			if(doc.HasMember("message"))
				if(doc["message"].IsObject())
					message = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["message"]));
				else
					std::cerr << "Error: Field \"message\" does not contain a json object." << std::endl;

			if(doc.HasMember("inline_message_id"))
				if(doc["inline_message_id"].IsString())
					inline_message_id = doc["inline_message_id"].GetString();
				else
					std::cerr << "Error: Field \"inline_message_id\" does not contain a string." << std::endl;

			if(doc.HasMember("chat_instance"))
				if(doc["chat_instance"].IsString())
					chat_instance = doc["chat_instance"].GetString();
				else
					std::cerr << "Error: Field \"chat_instance\" does not contain a string." << std::endl;

			if(doc.HasMember("data"))
				if(doc["data"].IsString())
					data = doc["data"].GetString();
				else
					std::cerr << "Error: Field \"data\" does not contain a string." << std::endl;

			if(doc.HasMember("game_short_name"))
				if(doc["game_short_name"].IsString())
					game_short_name = doc["game_short_name"].GetString();
				else
					std::cerr << "Error: Field \"game_short_name\" does not contain a string." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
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
